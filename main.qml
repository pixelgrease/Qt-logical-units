import QtQuick 2.4
import QtQuick.Window 2.2
import MyModule 1.0

Window {
    visible: true
    width: 4*UI.in; height: 3*UI.in

    Row {
        anchors.centerIn: parent
        spacing: 12*UI.pt

        Column {
            Text { text: "36 points"; font.pixelSize: 12*UI.pt }
            Rectangle { color: 'blue'; width: 36*UI.pt; height: width }
        }
        Column {
            Text { text: "12 mm"; font.pixelSize: 12*UI.pt }
            Rectangle { color: 'red'; width: 12*UI.mm; height: width }
        }
        Column {
            Text { text: "2 cm"; font.pixelSize: 12*UI.pt }
            Rectangle { color: 'green'; width: 2*UI.cm; height: width }
        }
        Column {
            Text { text: "1 inch"; font.pixelSize: 12*UI.pt }
            Rectangle { color: 'aqua'; width: 1*UI.in; height: width }
        }
    }

    // DPI label at top of window
    Text {
        function scaleUp() {
            UI.dpi = Math.max(12, 1.01*UI.dpi)
        }
        function scaleDown() {
            UI.dpi = Math.min(300, UI.dpi/1.01)
        }

        text: '%1 DPI'.arg(UI.dpi.toFixed(0))
        font.pointSize: 18
        anchors { top: parent.top; horizontalCenter: parent.horizontalCenter }
        focus: true
        Keys.onEscapePressed: Qt.quit()
        Keys.onRightPressed: scaleUp()
        Keys.onUpPressed: scaleUp()
        Keys.onLeftPressed: scaleDown()
        Keys.onDownPressed: scaleDown()
    }

    Text {
        text: 'Press arrows to change scale, ESC to exit'
        anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter }
        font.pixelSize: 12*UI.pt
    }
}
