#include "window.h"

Window::Window(QQuickItem *parent) :
    QQuickItem(parent)
{
    connect(this, SIGNAL(resize(QQuickWindow*)), this, SLOT(handleWindowChanged(QQuickWindow*)));
}

void Window::draw()
{
    // TODO draw OpenGL
}

void Window::resize(QQuickWindow* window)
{
    // resize gl
}
