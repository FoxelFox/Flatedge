#ifndef CAMERA_H
#define CAMERA_H

#include <QMatrix4x4>
#include <QOpenGLShaderProgram>

namespace Lens {
    enum lens_t {
        Ortho,
        Projection
    };
}


class Camera
{
public:
    Camera(QSize size);

    void toUniform(QOpenGLShaderProgram *shader);
    void setSize(QSize size);
    void setLens(Lens::lens_t lens);
    void update();

private:
    QMatrix4x4 m_view;
    QMatrix4x4 m_proj;
    QSize m_size;
    Lens::lens_t m_lens;

    float m_animation;
};

#endif // CAMERA_H
