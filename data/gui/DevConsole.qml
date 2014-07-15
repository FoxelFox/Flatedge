import QtQuick 2.0
import QtQuick.Controls 1.0
import Flatedge 1.0

Console {
    id: dev_console
    text: "Flatedge Engine"

    Rectangle {
        anchors.fill: parent
        color: Qt.rgba(0,0,0,0.4)
        Column {

            ScrollView {
                width: dev_console.width
                height: dev_console.height - dev_textfield.height
                Text {
                    text: dev_console.text
                    color: "white"
                    font.family: "Monospace"
                    font.bold: true
                }
            }
            TextField {
                id: dev_textfield
                width: dev_console.width

                Keys.onReturnPressed: {
                    dev_console.addLinetoLog(dev_textfield.text)
                }
            }
        }
    }
}
