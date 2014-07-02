import QtQuick 2.0
import QtQuick.Controls 1.0
import Flatedge 1.0

Console {
    id: dev_console
    text: "Flatedge Engine"
    Column {
        ScrollView {
            Text {
                text: dev_console.text
            }
        }
        TextField {
            id: dev_textfield
            Keys.onEnterPressed:  {
                dev_console.addLinetoLog(dev_textfield.text)
            }

        }
    }
}
