#ifndef ENGINE_H
#define ENGINE_H

#include <QMap>
#include <QList>

#include "src/render/object/factory.h"
#include "src/render/scene.h"

class QOpenGLShaderProgram;
class QObject;


class Engine
{
public:
    Engine(QObject *parent);
    void Draw();
    void Update();

    QOpenGLShaderProgram *getShader(QString name);

    /**
     * @brief Returns the QML OpenGLContext
     * @return OpenGLContext
     */
    QObject *getContext();


private:
    Factory *m_factory;
    QList<Scene*> m_scenes;
    QMap<QString, QOpenGLShaderProgram*> m_shaders;
    QObject *m_parent;
};

#endif // ENGINE_H
