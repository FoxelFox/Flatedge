#include "engine.h"
#include <QOpenGLShaderProgram>


Engine::Engine(QObject *parent)
{
    m_parent = parent;
    initializeOpenGLFunctions();
}

void Engine::Draw()
{
    glClearColor(0.0,0.75,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
        shader->addShaderFromSourceFile(QOpenGLShader::Fragment, QString(":/shader/" + name + ".frag"));
        shader->addShaderFromSourceFile(QOpenGLShader::Vertex, QString(":/shader/" + name + ".vert"));
        shader->link();
        m_shaders[name] = shader;
    }
    return shader;
}

QObject *Engine::getContext()
{
    return m_parent;
}
