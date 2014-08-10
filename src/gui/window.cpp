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
    m_window = 0;
    m_engine = 0;
}

void Window::draw()
{
    m_engine->Draw();
}

void Window::emitReDraw() {
    m_window->update();
}

void Window::destroy()
{

}

void Window::screenChanged(QScreen * screen)
{
    Console::sWrite("screen change");
}

void Window::resize()
{
    if(m_engine)
        m_engine->resize(m_window->size());
}

void Window::init()
{
    m_qmlContext = window()->openglContext();
    m_engine = new Engine(parent(), m_window->size());
}

void Window::windowChanged(QQuickWindow* window)
{
    m_window = window;
    // Window should now created
    if(window) {
        connect(window, SIGNAL(beforeRendering()), this, SLOT(draw()), Qt::DirectConnection);
        connect(window, SIGNAL(sceneGraphInitialized()), this, SLOT(init()), Qt::DirectConnection);



        connect(window, SIGNAL(afterRendering()), this, SLOT(emitReDraw()), Qt::DirectConnection);

        //connect(window, SIGNAL(screenChanged(QScreen*)), this, SLOT(screenChanged(QScreen*)), Qt::DirectConnection);
        connect(window, SIGNAL(widthChanged(int)), this, SLOT(resize()), Qt::DirectConnection);
        connect(window, SIGNAL(heightChanged(int)), this, SLOT(resize()), Qt::DirectConnection);

        window->setClearBeforeRendering(false);


    }
}
