#ifndef SCENE_H
#define SCENE_H

#include <QList>
#include <QOpenGLFunctions>

#include "src/render/engine.h"
#include "src/render/object/drawable.h"
#include "src/render/object/factory.h"
#include "src/render/camera.h"

class Scene : QOpenGLFunctions
{
public:
    Scene(Engine *engine, Factory *factory);

    void draw();
    void create();

private:

    Factory *m_factory;
    Engine *m_engine;

    GLuint m_ubo;
    QList<Drawable*> m_drawableList;
    QList<Camera*> m_cameraList;
};

#endif // SCENE_H
