#include "window.h"
#include "src/gui/console.h"

#include "src/render/engine.h"

#include <iostream>
#include <QQuickWindow>
#include <QOpenGLContext>


Window::Window(QQuickItem *parent) :
    QQuickItem(parent)
{
    connect(this, SIGNAL(windowChanged(QQuickWindow*)), this, SLOT(windowChanged(QQuickWindow*)));
}

void Window::draw()
{
    m_engine->Draw();
}

void Window::init()
{
    m_qmlContext = window()->openglContext();
    m_engine = new Engine(parent());
}

void Window::windowChanged(QQuickWindow* window)
{
    // Window should now created
    if(window) {
        connect(window, SIGNAL(beforeRendering()), this, SLOT(draw()), Qt::DirectConnection);
        connect(window, SIGNAL(sceneGraphInitialized()), this, SLOT(init()), Qt::DirectConnection);

        window->setClearBeforeRendering(false);

    }
}
