#ifndef ENGINE_H
#define ENGINE_H

#include <QMap>
#include <QOpenGLFunctions_4_3_Core>

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
    QOpenGLFunctions_4_3_Core c43;
    QMap<QString, QOpenGLShaderProgram*> m_shaders;
    QObject *m_parent;
};

#endif // ENGINE_H
