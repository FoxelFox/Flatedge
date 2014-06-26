#include "camera.h"


Camera::Camera()
{
    m_view.setToIdentity();
}

void Camera::toGPU()
{
    // todo uniform upload
}
