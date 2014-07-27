#ifndef TARGET_H
#define TARGET_H

#include <QVector>
#include <QOpenGLFunctions_4_3_Core>

class Texture;

class RenderTarget : protected QOpenGLFunctions_4_3_Core
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
