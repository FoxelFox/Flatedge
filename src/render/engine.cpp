#include "engine.h"
#include <QOpenGLShaderProgram>

#include <src/gui/console.h>
#include <src/render/scene.h>

Engine::Engine(QObject *parent)
{
    m_parent = parent;
    m_factory = new Factory(this);

    // create the default scene
    m_scenes.append(new Scene(this, m_factory));

    sCheckError();
}

void Engine::Draw()
{
    // glear the screen
    glClearColor(0.1,0.15,0.2,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw every scene
    foreach (Scene *scene, m_scenes) {
        scene->draw();
    }
}

void Engine::Update()
{

}

QOpenGLShaderProgram *Engine::getShader(QString name)
{
    QOpenGLShaderProgram* shader = m_shaders[name];


    // if the shader does not exist create a new
    if(!shader) {
        shader = new QOpenGLShaderProgram(m_parent);
        shader->addShaderFromSourceFile(QOpenGLShader::Fragment, QString(":shader/shader/" + name + ".frag"));
        shader->addShaderFromSourceFile(QOpenGLShader::Vertex, QString(":shader/shader/" + name + ".vert"));
        shader->link();
        m_shaders[name] = shader;
    }
    return shader;
}

QObject *Engine::getContext()
{
    return m_parent;
}

void Engine::sCheckError() {
    // TODO: trace errors
}
