TEMPLATE = app

QT += qml quick

SOURCES += \
    src/main.cpp \
    src/gui/window.cpp \
    src/gui/console.cpp \
    src/render/engine.cpp \
    src/render/target.cpp

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

OTHER_FILES +=

RESOURCES += \
    data/resource.qrc

HEADERS += \
    src/gui/window.h \
    src/gui/console.h \
    src/render/engine.h \
    src/render/target.h
