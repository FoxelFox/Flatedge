#include <QGuiApplication>
#include <QSurfaceFormat>
#include <QtQuick>

#include "src/gui/window.h"
#include "src/gui/console.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    qmlRegisterType<Window>("Flatedge", 1, 0, "Window");
    qmlRegisterType<Console>("Flatedge",1,0, "Console");


    QSurfaceFormat winFormat;
    winFormat.setVersion(2,1);
    winFormat.setSamples(4);
    winFormat.setStencilBufferSize(8); // ???
    winFormat.setProfile(QSurfaceFormat::CoreProfile);


    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/data/gui/main.qml"));
    view.setFormat(winFormat);
    view.show();

    return app.exec();
}
