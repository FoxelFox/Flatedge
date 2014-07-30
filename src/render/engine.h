#ifndef ENGINE_H
#define ENGINE_H

#include <QMap>
#include <QList>

#include "src/render/object/factory.h"

class QOpenGLShaderProgram;
class QObject;
class Scene;


class Engine
{
public:
    Engine(QObject *parent);
    void Draw();
    void Update();

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

private:
    Factory *m_factory;
    QList<Scene*> m_scenes;
    QMap<QString, QOpenGLShaderProgram*> m_shaders;
    QObject *m_parent;
};

#endif // ENGINE_H
