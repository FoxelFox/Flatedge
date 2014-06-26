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
