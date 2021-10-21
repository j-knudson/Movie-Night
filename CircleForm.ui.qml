import QtQuick 2.4

Item {
    width: 100
    height: 100
    property alias buttonColor: button.color
    property alias displayText: display.text

    Rectangle {
        id: button
        color: "#08a225"
        //radius: width*.5
        anchors.fill: parent

        Text {
            id: display
            x: 28
            y: 49
            color: "#fdfbfb"
            text: qsTr("OK")
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
