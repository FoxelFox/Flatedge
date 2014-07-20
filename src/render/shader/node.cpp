#include "node.h"

namespace Shader {

    Drawable *Node::sm_screenRectangle = 0;

    Node::Node(Engine *engine)
    {
        m_engine = engine;
        m_size = QSize(512,512);
        if(sm_screenRectangle == 0) {
            sm_screenRectangle = m_engine->getFactory()->GenRectangle();
        }
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

    void Node::Compute()
    {
        // size of texture inputs
        const int size = m_inputs.size();


        /** PREPARE FOR SHADER COMPUTE */

        // enable shader
        m_shader->bind();

        // enable rendertarget
        m_renderTarget->bind();

        // bind the texture inputs
        for(int i = 0; i < size; ++i) {
            m_inputs[i]->bind(i);
        }


        /** MAKE THE SHADER COMPUTE */

        // set the rendersize (pixels that are involved)
        glViewport(-m_size.width() / 2, -m_size.height() / 2,
                   +m_size.width() / 2, +m_size.height() / 2);

        // Draw a Rectangle to the Framebuffer
        QMatrix4x4 mat;
        sm_screenRectangle->draw(mat);


        /** CLEANUP USED RECOURCES */

        // release all texture inputs
        for(int i = 0; i < size; ++i) {
            m_inputs[i]->release();
        }

        // disable rendertarget
        m_renderTarget->release();

        // disable shader
        m_shader->release();
    }

    void Node::RemoveOutputSocket(int index)
    {

    }

    void Node::Bind()
    {
        m_shader->bind();
    }

    void Node::Release()
    {
        m_shader->release();
    }

    void Node::SetShader(QOpenGLShaderProgram *shader)
    {
        m_shader = shader;
    }


    void Node::generateHeader()
    {

    }
}
