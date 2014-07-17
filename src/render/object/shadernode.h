#ifndef SHADERNODE_H
#define SHADERNODE_H

#include "src/render/rendertarget.h"

#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QVector>


class ShaderNode
{
public:
    ShaderNode();

private:
    RenderTarget *m_renderTarget;
    QOpenGLShaderProgram *m_shader;
    QVector<QOpenGLTexture*> m_outputs;
    QVector<QOpenGLTexture*> m_inputs;
};

#endif // SHADERNODE_H
