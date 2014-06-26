#ifndef SCENE_H
#define SCENE_H

#include <QList>

#include "src/render/object/drawable.h"
#include "src/render/camera.h"

class Scene
{
public:
    Scene();

    void draw();

private:
    QList<Drawable*> m_drawableList;
    QList<Camera*> m_cameraList;
};

#endif // SCENE_H
