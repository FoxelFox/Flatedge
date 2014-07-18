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

        // TODO Reinit Framebuffer or create a new one
    }

    void Node::RemoveOutputSocket(int index)
    {

    }

    void Node::generateHeader()
    {

    }
}
