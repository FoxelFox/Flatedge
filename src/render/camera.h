#ifndef CAMERA_H
#define CAMERA_H

#include <QMatrix4x4>

class Camera
{
public:
    Camera();

    QMatrix4x4 view() { return m_view; }

private:
    QMatrix4x4 m_view;
};

#endif // CAMERA_H
