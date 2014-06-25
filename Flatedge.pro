TEMPLATE = app

QT += qml quick

SOURCES += \
    src/main.cpp \
    src/gui/window.cpp \
    src/gui/console.cpp \
    src/render/engine.cpp \
    src/render/rendertarget.cpp \
    src/render/object/drawable.cpp \
    src/render/object/factory.cpp \
    src/render/object/mesh.cpp

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
    src/render/rendertarget.h \
    src/render/object/drawable.h \
    src/render/object/factory.h \
    src/render/object/mesh.h
