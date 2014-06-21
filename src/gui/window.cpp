#include "window.h"
#include "src/gui/console.h"

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
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    //m_qmlContext->makeCurrent(window());
    //window()->update();
}

void Window::init()
{
    m_qmlContext = window()->openglContext();
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
