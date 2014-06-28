#include "scene.h"

#include "src/gui/console.h"

Scene::Scene(Factory *factory)
{
    m_factory = factory;
    m_cameraList.append(new Camera());
    create();
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
    m_drawableList.append(m_factory->GenRectangle(QVector3D(1.0f,1.0f,1.0f), QVector4D(1.0f,1.0f,1.0f,1.0f)));


    // create the global unifom buffer
    //glGenBuffers(1, &m_ubo);
    //glBindBuffer(GL_UNIFORM_BUFFER, m_ubo);
    //glBufferData(GL_UNIFORM_BUFFER, sizeof(QMatrix4x4) * 2, 0, GL_STREAM_DRAW);
    //glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
