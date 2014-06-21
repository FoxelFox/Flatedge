#ifndef WINDOW_H
#define WINDOW_H

#include <QQuickItem>

class Window : public QQuickItem
{
    Q_OBJECT
public:
    explicit Window(QQuickItem *parent = 0);

signals:

public slots:
    void draw();
    void resize(QQuickWindow *window);
};

#endif // WINDOW_H
