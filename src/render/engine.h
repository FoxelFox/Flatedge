#ifndef ENGINE_H
#define ENGINE_H

#include <QMap>
#include <QList>
#include <QSize>

#include "src/render/object/factory.h"

class QOpenGLShaderProgram;
class QObject;
class Scene;


class Engine
{
public:
    Engine(QObject *parent, QSize size);
    void Draw();
    void Update();
    void resize(QSize size);

    /**
     * @brief Returns a ShaderProgramm with that fragment end vertex shader.
     * @param frag FragmentShader
     * @param vert VertexShader
     * @return corresponding ShaderProgram
     */
    QOpenGLShaderProgram *getShader(QString vert, QString frag);

    static void sCheckError();

    /**
     * @brief Returns the QML OpenGLContext
     * @return OpenGLContext
     */
    QObject *getContext();

    /**
     * @brief Returns the Factory that build Drawables
     * @return The Factory
     */
    Factory *getFactory();

    QSize getRenderSize();

private:
    Factory *m_factory;
    QList<Scene*> m_scenes;
    QMap<QString, QOpenGLShaderProgram*> m_shaders;
    QObject *m_parent;
    QSize m_renderSize;
};

#endif // ENGINE_H
