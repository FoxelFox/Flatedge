#include "scene.h"
#include <iostream>

#include "src/gui/console.h"

Scene::Scene(Engine *engine, Factory *factory)
{
    m_engine = engine;
    m_factory = factory;

    Camera *cam = new Camera(m_engine->getRenderSize());
    cam->setLens(Lens::Ortho);
    m_cameraList.append(cam);

    //m_rootNode = new Shader::Node(engine, m_engine->getRenderSize());
    //m_rootNode->SetShader(m_engine->getShader("passthru", "passthru"));

    // add 3 output sockets
    //m_rootNode->AddOutputSocket();
    create();
}

void Scene::draw()
{
    /** Draw the scene in the first node **/
    // Bind root node
    //m_rootNode->StartRecord();

    // all draw calls are going into the rootNode
    QMatrix4x4 trans;
    trans.translate(0.0f,0.0f,-2.0f);
    foreach (Camera *cam, m_cameraList) {
        cam->setSize(m_engine->getRenderSize());
        cam->update();
        cam->toUniform(m_engine->getShader("basic", "basic"));
        foreach (Drawable *item, m_drawableList) {
            item->draw(trans);
        }
    }

    //m_rootNode->StopRecord();

    /** Start the postprocessing with the rendered scene **/
    // TODO: make postprocessing
    //m_rootNode->DrawOutput(0);
}

void Scene::create()
{
    Drawable *drawable = m_factory->GenBlock(QVector3D(10.0f,10.0f,1.0f), QVector4D(1.0f,0.0f,0.25f,1.0f));
    //Drawable *drawable = m_factory->GenRectangle();

    m_drawableList.append(drawable);


}

void Scene::resize(QSize size)
{
    foreach (Camera *cam, m_cameraList) {
        cam->setSize(size);
    }
}
