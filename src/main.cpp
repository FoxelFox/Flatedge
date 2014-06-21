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

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/data/gui/main.qml"));
    view.show();

    return app.exec();
}
