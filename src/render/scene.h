#ifndef SCENE_H
#define SCENE_H

#include <QList>
#include <QOpenGLFunctions>

#include "src/render/object/drawable.h"
#include "src/render/object/factory.h"
#include "src/render/camera.h"

class Scene : QOpenGLFunctions
{
public:
    Scene(Factory *factory);

    void draw();
    void create();

private:

    Factory *m_factory;

    GLuint m_ubo;
    QList<Drawable*> m_drawableList;
    QList<Camera*> m_cameraList;
};

#endif // SCENE_H
