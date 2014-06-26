#ifndef CAMERA_H
#define CAMERA_H

#include <QMatrix4x4>

#include <QOpenGLFunctions_4_3_Core>

class Camera : protected QOpenGLFunctions_4_3_Core
{
public:
    Camera();

    void toGPU();

    QMatrix4x4 view() { return m_view; }

private:
    QMatrix4x4 m_view;
};

#endif // CAMERA_H
