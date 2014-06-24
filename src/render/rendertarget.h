#ifndef TARGET_H
#define TARGET_H

#include <QVector>
#include <QOpenGLFunctions>

class QOpenGLTexture;

class RenderTarget : protected QOpenGLFunctions
{
public:
    RenderTarget(QVector<QOpenGLTexture*> textureBuffers);

    void bind();
    void release();
    void clear();
    void destroy();
    void create();
private:
    GLuint m_frameBuffer;
    GLuint m_depthBuffer;
    QVector<QOpenGLTexture*> m_textureBuffers;

};

#endif // TARGET_H
