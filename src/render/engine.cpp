#include "engine.h"
#include <QOpenGLShaderProgram>
#include <iostream>

#include <src/gui/console.h>
#include <src/render/scene.h>

Engine::Engine(QObject *parent, QSize size)
{
    m_parent = parent;
    m_renderSize = size;
    m_factory = new Factory(this);

    // create the default scene
    m_scenes.append(new Scene(this, m_factory));

    sCheckError();
}

void Engine::Draw()
{
    // glear the screen
    glClearColor(0.1,0.15,0.2,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Draw every scene
    foreach (Scene *scene, m_scenes) {
        scene->draw();
    }

}

void Engine::Update()
{

}

void Engine::resize(QSize size)
{
    m_renderSize = size;
}

QOpenGLShaderProgram *Engine::getShader(QString vert, QString frag)
{
    QOpenGLShaderProgram* shader = m_shaders[frag + vert];


    // if the shader does not exist create a new
    if(!shader) {
        shader = new QOpenGLShaderProgram(m_parent);
        shader->addShaderFromSourceFile(QOpenGLShader::Fragment, QString(":shader/shader/" + frag + ".frag"));
        shader->addShaderFromSourceFile(QOpenGLShader::Vertex, QString(":shader/shader/" + vert + ".vert"));
        shader->link();
        m_shaders[frag + vert] = shader;
    }
    return shader;
}

QObject *Engine::getContext()
{
    return m_parent;
}

Factory *Engine::getFactory()
{
    return m_factory;
}

QSize Engine::getRenderSize()
{
    return m_renderSize;
}

void Engine::sCheckError() {
    // TODO: trace errors
}
