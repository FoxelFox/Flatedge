#ifndef NODE_H
#define NODE_H

#include "src/render/rendertarget.h"
#include "src/render/engine.h"
#include "src/render/object/mesh.h"

#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QVector>
#include <QString>
#include <QSize>


namespace Shader {


    class Node
    {
    public:
        Node(Engine *engine);

        void AddInputSocket(QOpenGLTexture* input);
        void RemoveInputSocket(int index);

        void AddOutputSocket();
        void RemoveOutputSocket(int index);

        void Bind();
        void Release();

        void SetShader(QOpenGLShaderProgram *shader);

        void StartRecord();

        void StopRecord();

        /**
         * @brief Executes the Shader and writes the output into the Framebuffer.
         */
        void Compute();

        /**
         * @brief Draw one output to the screen.
         * @param index Output index to draw
         */
        void DrawOutput(int index);

        void *GetOutputTexture(int index);

    private:

        void generateHeader();

        // static objects
        static Drawable *sm_screenRectangle;

        // own objects
        RenderTarget *m_renderTarget;
        QVector<QOpenGLTexture*> m_outputs;
        QSize m_size;

        // reference from other objects
        QOpenGLShaderProgram *m_shader;
        QVector<QOpenGLTexture*> m_inputs;
        Engine *m_engine;

    };
}

#endif // NODE_H
