import QtQuick 2.2
import QtQuick.Controls 1.0
import Flatedge 1.0

Window {
    width: 1280
    height: 720

    DevConsole{
        anchors.bottom: parent.bottom
        width: 420
        height: 280

    }

    Keys.onEscapePressed: Qt.quit()
}
