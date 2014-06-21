#ifndef ENGINE_H
#define ENGINE_H

#include <QMap>

class QOpenGLShaderProgram;
class QObject;

class Engine
{
public:
    Engine(QObject *parent);
    void Draw();
    void Update();
    QOpenGLShaderProgram* GetShader(QString name);

private:
    QMap<QString, QOpenGLShaderProgram*> m_shaders;
    QObject *m_parent;
};

#endif // ENGINE_H
