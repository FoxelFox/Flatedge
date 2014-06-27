#include "scene.h"

Scene::Scene()
{
}

void Scene::draw()
{
    QMatrix4x4 trans;
    foreach (Camera *cam, m_cameraList) {

        cam->toGPU();
        foreach (Drawable *item, m_drawableList) {
            item->draw(trans);
        }
    }
}

void Scene::create()
{
    // create the global unifom buffer
    glGenBuffers(1, &m_ubo);
    glBindBuffer(GL_UNIFORM_BUFFER, m_ubo);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(QMatrix4x4) * 2, 0, GL_STREAM_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
