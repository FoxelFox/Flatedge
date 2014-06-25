#include "scene.h"

Scene::Scene()
{
}

void Scene::draw()
{
    QMatrix4x4 trans;
    foreach (Drawable *item, m_drawableList) {
        item->draw(trans);
    }
}
