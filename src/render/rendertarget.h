#ifndef TARGET_H
#define TARGET_H

#include <QVector>
#include <QOpenGLFunctions_ES2>

class Texture;

class RenderTarget : protected QOpenGLFunctions_ES2
{
public:
    RenderTarget(QVector<Texture*> textureBuffers);

    void bind();
    void release();
    void clear();
    void destroy();
    void create();
private:
    GLuint m_frameBuffer;
    GLuint m_depthBuffer;
    GLenum m_drawbuffs[16];
    QVector<Texture*> m_textureBuffers;

};

#endif // TARGET_H
