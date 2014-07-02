#include "scene.h"

#include "src/gui/console.h"

Scene::Scene(Engine *engine, Factory *factory)
{
    m_engine = engine;
    m_factory = factory;
    m_cameraList.append(new Camera(QSize(1280,720)));
    create();
}

void Scene::draw()
{
    QMatrix4x4 trans;
    foreach (Camera *cam, m_cameraList) {
        cam->update();
        cam->toUniform(m_engine->getShader("basic"));
        foreach (Drawable *item, m_drawableList) {
            item->draw(trans);
        }
    }
}

void Scene::create()
{
    Drawable *drawable = m_factory->GenBlock(QVector3D(2.0f,2.0f,1.0f), QVector4D(1.0f,0.0f,0.25f,1.0f));

    //QMatrix4x4 mat;
    //mat.setToIdentity();
    //mat.translate(0,0,-10.5);
    //mat.rotate(90,1,0,0);

    //drawable->SetTransformMatrix(mat);
    m_drawableList.append(drawable);

    // create the global unifom buffer
    //glGenBuffers(1, &m_ubo);
    //glBindBuffer(GL_UNIFORM_BUFFER, m_ubo);
    //glBufferData(GL_UNIFORM_BUFFER, sizeof(QMatrix4x4) * 2, 0, GL_STREAM_DRAW);
    //glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
