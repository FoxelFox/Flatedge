#ifndef FACTORY_H
#define FACTORY_H

class Drawable;
class QOpenGLShaderProgram;
class QVector4D;
class QVector3D;
class Engine;
class Mesh;

///
/// \brief The Factory class Produces Drawables
/// \author André Furchner
///
class Factory
{
public:

    ///
    /// \brief Create a new Factory
    /// \param engine The RenderEngine Context
    ///
    Factory(Engine *engine);

    ///
    /// \brief Generate a new Rectangle
    /// \param size Size of the Rectangle
    /// \param color Color for the Rectangle
    /// \param shader Shader to be used when Draw
    /// \return A new Drawable that is a Rectangle
    ///
    Drawable *GenRectangle(QVector3D size, QVector4D color);

    ///
    /// \brief Generate a new Block
    /// \param size Size of the Block
    /// \param color Color for the Block
    /// \param shader Shader to be used when Draw
    /// \return A new Drawable that is a Block
    ///
    Drawable *GenBlock(QVector3D size, QVector4D color);

    ///
    /// \brief Generate a new Sphere
    /// \param size Size for the Sphere
    /// \param color Color
    /// \return
    ///
    Drawable *GenSphere(QVector3D size, QVector4D color);

private:

    Engine *m_engine;               ///< The RenderEngine Context
    Mesh *m_rectangle;              ///< The Default Rectangle Mesh
    Mesh *m_block;                  ///< The Default Block Mesh

    void createMeshRectangle();
    void createMeshBlock();
};

#endif // FACTORY_H
