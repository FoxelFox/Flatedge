#ifndef SCENE_H
#define SCENE_H

#include <QList>
#include <QOpenGLFunctions>

#include "src/render/engine.h"
#include "src/render/object/drawable.h"
#include "src/render/object/factory.h"
#include "src/render/camera.h"
#include "src/render/shader/node.h"

class Scene : QOpenGLFunctions
{
public:
    Scene(Engine *engine, Factory *factory);

    void draw();
    void create();
    void resize(QSize size);

private:

    Factory *m_factory;
    Engine *m_engine;

    GLuint m_ubo;
    QList<Drawable*> m_drawableList;
    QList<Camera*> m_cameraList;
    Shader::Node *m_rootNode;
};

#endif // SCENE_H
