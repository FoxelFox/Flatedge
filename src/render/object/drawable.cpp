#include "drawable.h"
#include "src/gui/console.h"
#include "src/render/engine.h"
#include "src/render/object/mesh.h"
#include <iostream>
#include <cmath>

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
using namespace std;

Drawable::Drawable(Engine *engine, QMatrix4x4 transform)
{
    m_shader = NULL;
    m_mesh = NULL;
    m_modelMatrix.setToIdentity();
    m_engine = engine;
    m_transMatrix = transform;
}

void Drawable::draw(QMatrix4x4 &transform)
{
    // bind my shader to be used
    m_shader->bind();

    // set my uniform color
    m_shader->setUniformValue("uColor", m_color);

    // calculate and set uniform variable modelMatrix
    m_SceneMatrix = transform * m_transMatrix;
    m_shader->setUniformValue("uScen", m_SceneMatrix);
    m_shader->setUniformValue("uModl", m_modelMatrix);

    // draw myself
    m_mesh->Draw();
    m_shader->release();

    // draw my childs
    for(unsigned int i = 0; i < m_childList.size(); ++i) {
        m_childList[i]->draw(m_SceneMatrix);
    }
}

void Drawable::Build()
{
    // first check for wrong usage
    if(m_shader == NULL) {
        Console::sWriteError("No Shader assigned for this Drawable!");
        return;
    }

    if(m_mesh == NULL) {
        Console::sWriteError("No Mesh is assigned to this Drawable!");
        return;
    }

    m_mesh->BuildVAO(m_engine->getContext(), m_shader);

}

void Drawable::SetMesh(Mesh *mesh)
{
    m_mesh = mesh;
}

void Drawable::SetShader(QOpenGLShaderProgram *shader)
{
    m_shader = shader;
}

void Drawable::SetModelMatrix(QMatrix4x4 matrix)
{
    m_modelMatrix = matrix;
}

QMatrix4x4 Drawable::GetModelMatrix()
{
    return m_modelMatrix;
}

void Drawable::SetTransformMatrix(QMatrix4x4 matrix)
{
    m_transMatrix = matrix;
}

QMatrix4x4 Drawable::GetTransformMatrix()
{
    return m_transMatrix;
}

void Drawable::AddChild(Drawable *child, QMatrix4x4 transform)
{
    child->m_transMatrix = transform;
    m_childList.push_back(child);
}

void Drawable::SetColor(QVector4D color)
{
    m_color = color;
}

Drawable *Drawable::GetChild(int index)
{
    return m_childList[index];
}

int Drawable::GetChildCount()
{
    return m_childList.size();
}

QMatrix4x4 Drawable::GetSceneMatrix()
{
        return m_SceneMatrix;
}
