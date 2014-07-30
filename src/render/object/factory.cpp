#include "factory.h"

#include "src/render/object/drawable.h"
#include "src/render/engine.h"
#include "src/render/object/mesh.h"
#include "src/gui/console.h"

#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QDataStream>


Factory::Factory(Engine *engine)
{
    m_engine = engine;
    m_rectangle = 0;
    m_block = 0;
    m_sphere = 0;

    createMeshRectangle();
    createMeshBlock();
}

Drawable* Factory::GenRectangle(QVector3D size,  QVector4D color) {

    // create internal model matrix that create the size
    QMatrix4x4 modelMatrix;
    modelMatrix.setToIdentity();
    modelMatrix.scale(size);

    // create a new Drawable to be a Rectangle
    Drawable *rect = new Drawable(m_engine, QMatrix4x4());
    rect->SetMesh(m_rectangle);
    rect->SetModelMatrix(modelMatrix);
    rect->SetShader(m_engine->getShader("basic", "basic"));
    rect->SetColor(color);

    return rect;
}

Drawable *Factory::GenBlock(QVector3D size, QVector4D color)
{
    // create internal model matrix that create the size
    QMatrix4x4 modelMatrix;
    modelMatrix.setToIdentity();
    modelMatrix.scale(size);

    // create a new Drawable to be a Block
    Drawable *block = new Drawable(m_engine, QMatrix4x4());
    block->SetMesh(m_block);
    block->SetModelMatrix(modelMatrix);
    block->SetShader(m_engine->getShader("basic", "basic"));
    block->SetColor(color);

    return block;
}

Drawable *Factory::GenSphere(QVector3D size, QVector4D color)
{
    // TODO:
}

Mesh *Factory::GetRectangleMesh()
{
    return m_rectangle;
}

void Factory::createMeshRectangle()
{
    QVector3D normal[] = {
        QVector3D(+0.0, -1.0, +0.0),
        QVector3D(+0.0, -1.0, +0.0),
        QVector3D(+0.0, -1.0, +0.0),

        QVector3D(+0.0, -1.0, +0.0),
        QVector3D(+0.0, -1.0, +0.0),
        QVector3D(+0.0, -1.0, +0.0),
    };

    QVector3D vert[] = {
        QVector3D(+0.5, +0.0, +0.5),
        QVector3D(-0.5, -0.0, -0.5),
        QVector3D(-0.5, +0.0, +0.5),

        QVector3D(+0.5, +0.0, +0.5),
        QVector3D(+0.5, -0.0, -0.5),
        QVector3D(-0.5, -0.0, -0.5),
    };

    m_rectangle = new Mesh();
    m_rectangle->SetVertices(vert,6);
    m_rectangle->SetNormals(normal,6);
    m_rectangle->BuildVAO(m_engine->getContext(),m_engine->getShader("basic", "basic"));
}

void Factory::createMeshBlock()
{
    QVector3D normal[] = {

        // TOP
        QVector3D(+0.0, +0.0, +1.0),
        QVector3D(+0.0, +0.0, +1.0),
        QVector3D(+0.0, +0.0, +1.0),

        QVector3D(+0.0, +0.0, +1.0),
        QVector3D(+0.0, +0.0, +1.0),
        QVector3D(+0.0, +0.0, +1.0),


        // BOTOM
        QVector3D(+0.0, +0.0, -1.0),
        QVector3D(+0.0, +0.0, -1.0),
        QVector3D(+0.0, +0.0, -1.0),

        QVector3D(+0.0, +0.0, -1.0),
        QVector3D(+0.0, +0.0, -1.0),
        QVector3D(+0.0, +0.0, -1.0),


        // Left
        QVector3D(-1.0, +0.0, +0.0),
        QVector3D(-1.0, +0.0, +0.0),
        QVector3D(-1.0, +0.0, +0.0),

        QVector3D(-1.0, +0.0, +0.0),
        QVector3D(-1.0, +0.0, +0.0),
        QVector3D(-1.0, +0.0, +0.0),


        // Right
        QVector3D(+1.0, +0.0, +0.0),
        QVector3D(+1.0, +0.0, +0.0),
        QVector3D(+1.0, +0.0, +0.0),

        QVector3D(+1.0, +0.0, +0.0),
        QVector3D(+1.0, +0.0, +0.0),
        QVector3D(+1.0, +0.0, +0.0),


        // Back
        QVector3D(0.0, 1.0, +0.0),
        QVector3D(0.0, 1.0, +0.0),
        QVector3D(0.0, 1.0, +0.0),

        QVector3D(0.0, 1.0, +0.0),
        QVector3D(0.0, 1.0, +0.0),
        QVector3D(0.0, 1.0, +0.0),


        // Front
        QVector3D(0.0, -1.0, +0.0),
        QVector3D(0.0, -1.0, +0.0),
        QVector3D(0.0, -1.0, +0.0),

        QVector3D(0.0, -1.0, +0.0),
        QVector3D(0.0, -1.0, +0.0),
        QVector3D(0.0, -1.0, +0.0),
    };

    QVector3D vert[] = {

        // TOP
        QVector3D(+0.5, +0.5, +0.5),
        QVector3D(-0.5, +0.5, +0.5),
        QVector3D(-0.5, -0.5, +0.5),

        QVector3D(+0.5, +0.5, +0.5),
        QVector3D(-0.5, -0.5, +0.5),
        QVector3D(+0.5, -0.5, +0.5),


        // BOTOM
        QVector3D(-0.5, +0.5, -0.5),
        QVector3D(+0.5, +0.5, -0.5),
        QVector3D(-0.5, -0.5, -0.5),

        QVector3D(-0.5, -0.5, -0.5),
        QVector3D(+0.5, +0.5, -0.5),
        QVector3D(+0.5, -0.5, -0.5),


        // LEFT
        QVector3D( -0.5, -0.5, +0.5),
        QVector3D( -0.5, +0.5, +0.5),
        QVector3D( -0.5, -0.5, -0.5),

        QVector3D( -0.5, -0.5, -0.5),
        QVector3D( -0.5, +0.5, +0.5),
        QVector3D( -0.5, +0.5, -0.5),


        // RIGHT
        QVector3D( +0.5, +0.5, +0.5),
        QVector3D( +0.5, -0.5, +0.5),
        QVector3D( +0.5, -0.5, -0.5),

        QVector3D( +0.5, +0.5, +0.5),
        QVector3D( +0.5, -0.5, -0.5),
        QVector3D( +0.5, +0.5, -0.5),


        // BACK
        QVector3D( -0.5, +0.5, +0.5),
        QVector3D( +0.5, +0.5, +0.5),
        QVector3D( -0.5, +0.5, -0.5),

        QVector3D( -0.5, +0.5, -0.5),
        QVector3D( +0.5, +0.5, +0.5),
        QVector3D( +0.5, +0.5, -0.5),


        // FRONT
        QVector3D( +0.5, -0.5, +0.5),
        QVector3D( -0.5, -0.5, +0.5),
        QVector3D( -0.5, -0.5, -0.5),

        QVector3D( +0.5, -0.5, +0.5),
        QVector3D( -0.5, -0.5, -0.5),
        QVector3D( +0.5, -0.5, -0.5),

    };

    m_block = new Mesh();
    m_block->SetVertices(vert,36);
    m_block->SetNormals(normal,36);
    m_block->BuildVAO(m_engine->getContext(),m_engine->getShader("basic", "basic"));
}
