#include "camera.h"



Camera::Camera(QSize size)
{
    m_lens = Lens::Projection;
    m_view.setToIdentity();
    m_proj.setToIdentity();
    m_animation = 0.0f;
    setSize(size);
}

void Camera::toUniform(QOpenGLShaderProgram *shader)
{
    shader->bind();
    shader->setUniformValue("uProj", m_proj);
    shader->setUniformValue("uView", m_view);
    shader->release();
}

void Camera::setSize(QSize size)
{
    m_size = size;
}

void Camera::setLens(Lens::lens_t lens)
{
    m_lens = lens;
    update();
}

void Camera::update()
{

    glViewport(0, 0, m_size.width(), m_size.height());

    switch (m_lens) {
    case Lens::Ortho:
        m_proj.ortho(-1.0f,1.0f,-1.0f,1.0f, 1.0f, 10.0f);
        break;
    case Lens::Projection:
        m_proj.perspective(90.0f, (float)m_size.width () / (float)m_size.height(), 1.0f, 10.0f);
        break;
    default:
        m_proj.setToIdentity();
        break;
    }

    // TODO: remove this later
    //m_view.rotate(0.01f, 0.0f,1.0f,1.0f);
}


