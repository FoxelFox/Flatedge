#include <QGuiApplication>
#include <QtQuick>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/data/gui/main.qml"));
    view.show();

    return app.exec();
}
