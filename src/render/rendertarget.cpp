#include "rendertarget.h"

#include <QOpenGLTexture>

RenderTarget::RenderTarget(QVector<QOpenGLTexture*> textureBuffers)
{

    m_textureBuffers = textureBuffers;
    m_frameBuffer = 0;
    m_depthBuffer = 0;
}

void RenderTarget::create() {

    glGenFramebuffers(1, &m_frameBuffer);

    m_textureBuffers[0]->

    bind();

    GLenum drawbufs = 0;
    // setup framebuffer textures
    for(int i = 0; i < m_textureBuffers.size(); ++i) {
        if(!m_textureBuffers[i]->isCreated()) {
            m_textureBuffers[i]->create();
        }
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, m_textureBuffers[i]->textureId(),0);
        drawbufs |= GL_COLOR_ATTACHMENT0 + i;
    }

    // create depth-buffer as render-buffer
    glGenRenderbuffers(1, &m_depthBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_depthBuffer);

    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT32, m_textureBuffers[0]->width(), m_textureBuffers[0]->height());
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depthBuffer);


    glDrawBuffer(drawbufs);
    release();
}

void RenderTarget::bind() {
    glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);
}

void RenderTarget::release() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void RenderTarget::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderTarget::destroy() {
    for (int i = 0; i < m_textureBuffers.size(); ++i) {
        m_textureBuffers[i]->destroy();
    }
    if (m_frameBuffer != 0)
        glDeleteFramebuffers(1, &m_frameBuffer);

    if (m_depthBuffer != 0)
        glDeleteRenderbuffers(1, &m_depthBuffer);
}
