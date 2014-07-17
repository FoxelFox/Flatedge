#ifndef NODE_H
#define NODE_H

#include "src/render/rendertarget.h"

#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QVector>


namespace Shader {


    class Node
    {
    public:
        Node();

    private:
        RenderTarget *m_renderTarget;
        QOpenGLShaderProgram *m_shader;
        QVector<QOpenGLTexture*> m_outputs;
        QVector<QOpenGLTexture*> m_inputs;
    };
}

#endif // NODE_H
