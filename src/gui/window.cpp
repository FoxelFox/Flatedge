#include "window.h"
#include "src/gui/console.h"
#include <iostream>

Window::Window(QQuickItem *parent) :
    QQuickItem(parent)
{
    connect(this, SIGNAL(windowChanged(QQuickWindow*)), this, SLOT(windowChanged(QQuickWindow*)));

}

void Window::draw()
{
    // TODO draw OpenGL
}

void Window::windowChanged(QQuickWindow* window)
{
    // Window should now created
    if(window) {

    }
    // resize gl
}
