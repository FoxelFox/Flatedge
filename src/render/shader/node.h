#ifndef NODE_H
#define NODE_H

#include "src/render/rendertarget.h"
#include "src/render/engine.h"

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

        void Compile();
        void Bind();
        void Release();


    private:

        void generateHeader();

        // own objects
        RenderTarget *m_renderTarget;
        QOpenGLShaderProgram *m_shader;
        QVector<QOpenGLTexture*> m_outputs;
        QString m_header;
        QString m_code;
        QSize m_size;

        // reference from other objects
        QVector<QOpenGLTexture*> m_inputs;
        Engine *m_engine;

    };
}

#endif // NODE_H
