#include "scene.h"

#include "src/gui/console.h"

Scene::Scene(Factory *factory)
{
    m_factory = factory;
    m_cameraList.append(new Camera());
    create();
}

void Scene::draw()
{
    QMatrix4x4 trans;
    foreach (Camera *cam, m_cameraList) {

        cam->toGPU();
        foreach (Drawable *item, m_drawableList) {
            item->draw(trans);
        }
    }
}

void Scene::create()
{
    Drawable *drawable = m_factory->GenBlock(QVector3D(1.0f,1.0f,1.0f), QVector4D(1.0f,0.0f,0.25f,1.0f));

    QMatrix4x4 mat;
    //mat.translate(0,0,-10);
    drawable->SetTransformMatrix(mat);
    m_drawableList.append(drawable);

    // create the global unifom buffer
    //glGenBuffers(1, &m_ubo);
    //glBindBuffer(GL_UNIFORM_BUFFER, m_ubo);
    //glBufferData(GL_UNIFORM_BUFFER, sizeof(QMatrix4x4) * 2, 0, GL_STREAM_DRAW);
    //glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
