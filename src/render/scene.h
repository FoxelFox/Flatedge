#ifndef SCENE_H
#define SCENE_H

#include <QList>
#include <QOpenGLFunctions>

#include "src/render/object/drawable.h"
#include "src/render/camera.h"

class Scene : QOpenGLFunctions
{
public:
    Scene();

    void draw();
    void create();

private:
    GLuint m_ubo;
    QList<Drawable*> m_drawableList;
    QList<Camera*> m_cameraList;
};

#endif // SCENE_H
