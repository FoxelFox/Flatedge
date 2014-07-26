#include "node.h"
#include "src/render/object/drawable.h"

namespace Shader {

    Drawable *Node::sm_screenRectangle = 0;

    Node::Node(Engine *engine)
    {
        m_engine = engine;
        m_size = QSize(512,512);
        m_renderTarget = 0;
        if(sm_screenRectangle == 0) {
            sm_screenRectangle = m_engine->getFactory()->GenRectangle(QVector3D(2.0,2.0,2.0));
            sm_screenRectangle->SetShader(m_engine->getShader("uv_texture"));
        }
        initializeOpenGLFunctions();
    }

    void Node::AddInputSocket(Texture *input)
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
        Texture *tex = new Texture(m_size.width(), m_size.height());
        tex->CreateOnGPU();
        m_outputs.append(tex);

        // now simply create a new RenderTarget and destroy the old one //
        if(m_renderTarget != 0)
            m_renderTarget->destroy();
        m_renderTarget = new RenderTarget(m_outputs);
        m_renderTarget->create();
    }

    void Node::Compute()
    {
        // prepare
        Bind();


        /** MAKE THE SHADER COMPUTE */

        // set the rendersize (pixels that are involved)
        glViewport(-m_size.width() / 2, -m_size.height() / 2,
                   +m_size.width() / 2, +m_size.height() / 2);

        // Draw a Rectangle to the Framebuffer
        QMatrix4x4 mat;
        sm_screenRectangle->draw(mat);


        // cleanup
        Release();
    }

    void Node::DrawOutput(int index)
    {
        // activate simple texture draw shader
        QOpenGLShaderProgram *uv_tex_shader = m_engine->getShader("uv_texture");
        uv_tex_shader->bind();

        m_outputs[index]->bind(index);

        // Now draw a simple textured quad to screen
        QMatrix4x4 mat;
        mat.rotate(-90.0f,1.0f,0.0f);
        sm_screenRectangle->draw(mat);


        // cleanup
        m_outputs[index]->release();
        uv_tex_shader->release();
    }

    void *Node::GetOutputTexture(int index)
    {
        return m_outputs[index];
    }

    void Node::RemoveOutputSocket(int index)
    {

    }

    void Node::Bind()
    {
        // enable shader
        m_shader->bind();

        // enable rendertarget
        m_renderTarget->bind();

        // bind the texture inputs
        const int size = m_inputs.size();
        for(int i = 0; i < size; ++i) {
            m_inputs[i]->bind(i);
        }
    }



    void Node::Release()
    {
        // release all texture inputs
        const int size = m_inputs.size();
        for(int i = 0; i < size; ++i) {
            m_inputs[i]->release();
        }

        // disable rendertarget
        m_renderTarget->release();

        // disable shader
        m_shader->release();
    }

    void Node::SetShader(QOpenGLShaderProgram *shader)
    {
        m_shader = shader;
    }

    void Node::StartRecord()
    {
        m_renderTarget->bind();
    }

    void Node::StopRecord()
    {
        m_renderTarget->release();
    }


    void Node::generateHeader()
    {

    }
}
