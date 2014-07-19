#include "node.h"

namespace Shader {
    Node::Node(Engine *engine)
    {
        m_engine = engine;
        m_size = QSize(512,512);
    }

    void Node::AddInputSocket(QOpenGLTexture *input)
    {
        m_inputs.append(input);
        generateHeader();
    }

    void Node::RemoveInputSocket(int index)
    {
        m_inputs.remove(index);
        generateHeader();
    }

    void Node::AddOutputSocket()
    {
        QOpenGLTexture *texture = new QOpenGLTexture(QOpenGLTexture::Target2D);
        texture->setSize(m_size.width(), m_size.height());
        texture->create();
        texture->bind();
        texture->allocateStorage();
        m_outputs.append(texture);

        // now simply create a new RenderTarget and destroy the old one //
        m_renderTarget->destroy();
        m_renderTarget = new RenderTarget(m_outputs);
        m_renderTarget->create();
    }

    void Node::RemoveOutputSocket(int index)
    {

    }

    void Node::Compile()
    {
        m_shader = new QOpenGLShaderProgram(m_engine->getContext());
        m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, m_header + m_code);
        m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, QString("todo_shader.vert"));
        m_shader->link();
    }

    void Node::Bind()
    {
        m_shader->bind();
    }

    void Node::Release()
    {
        m_shader->release();
    }

    void Node::generateHeader()
    {

    }
}
