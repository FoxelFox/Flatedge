#ifndef NODE_H
#define NODE_H

#include "src/render/rendertarget.h"
#include "src/render/engine.h"
#include "src/render/object/mesh.h"
#include "src/render/texture.h"

#include <QOpenGLFunctions>
#include <QPair>
#include <QOpenGLShaderProgram>
#include <QVector>
#include <QString>
#include <QSize>


namespace Shader {


    class Node : public QOpenGLFunctions
    {
    public:
        Node(Engine *engine, QSize size);

        /**
         * @brief connect @socket from @node at @input from this Node
         * @param node other Node
         * @param socket Socket from other Node
         * @param input Socket for this Node
         */
        void connect(Node* node, int socket, int input);

        void RemoveInputSocket(int index);

        void AddOutputSocket();
        void RemoveOutputSocket(int index);

        void Bind();
        void Release();

        void SetShader(QOpenGLShaderProgram *shader);

        void StartRecord();

        void StopRecord();

        void setSamples(float samples);

        /**
         * @brief Executes the Shader and writes the output into the Framebuffer.
         */
        void Compute();

        /**
         * @brief Draw one output to the screen.
         * @param index Output index to draw
         */
        void DrawOutput(int index);

        Texture *GetOutputTexture(int index);

    private:

        void generateHeader();

        // static objects
        static Drawable *sm_screenRectangle;

        // own objects
        RenderTarget *m_renderTarget;
        QVector<Texture*> m_outputs;
        QSize m_size;

        // reference from other objects
        QOpenGLShaderProgram *m_shader;
        QVector<QPair<Node*, Texture*> > m_inputs;
        Engine *m_engine;
        float m_samples;

    };
}

#endif // NODE_H
