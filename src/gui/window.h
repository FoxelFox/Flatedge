#ifndef WINDOW_H
#define WINDOW_H

#include <QQuickItem>

class QOpenGLContext;
class Engine;

class Window : public QQuickItem
{
    Q_OBJECT
public:
    explicit Window(QQuickItem *parent = 0);

signals:

public slots:
    void draw();
    void init();
    void emitReDraw(); // dirty redraw hack
    void destroy();

private slots:
    void windowChanged(QQuickWindow *win);

private:


    QQuickWindow *m_window;
    QOpenGLContext *m_qmlContext;
    Engine *m_engine;
};

#endif // WINDOW_H
