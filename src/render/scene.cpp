#include "scene.h"

#include "src/gui/console.h"

Scene::Scene(Engine *engine, Factory *factory)
{
    m_engine = engine;
    m_factory = factory;
    m_cameraList.append(new Camera(QSize(1280,720)));
    m_nodeRoot = new Shader::Node(engine);
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
    //Drawable *drawable = m_factory->GenBlock(QVector3D(2.0f,2.0f,1.0f), QVector4D(1.0f,0.0f,0.25f,1.0f));
    Drawable *drawable = m_factory->GenRectangle();

    m_drawableList.append(drawable);


}
