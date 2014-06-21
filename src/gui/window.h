#ifndef WINDOW_H
#define WINDOW_H

#include <QQuickItem>

class QOpenGLContext;

class Window : public QQuickItem
{
    Q_OBJECT
public:
    explicit Window(QQuickItem *parent = 0);

signals:

public slots:
    void draw();
    void init();

private slots:
    void windowChanged(QQuickWindow *win);

private:
    QOpenGLContext *m_qmlContext;
};

#endif // WINDOW_H
