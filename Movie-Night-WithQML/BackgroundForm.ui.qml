import QtQuick 2.4
import QtQuick.Layouts 1.0

Item {
    Rectangle {
        id: bgRect
        color: "#e0a2b720"
        anchors.fill: parent

        GridLayout {
            anchors.fill: parent
            rowSpacing: 2
            columnSpacing: 2
            rows: 1
            columns: 2

            Rectangle {
                id: bgTopLeft
                color: "#00ffffff"
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredHeight: 200
                Layout.preferredWidth: 200

                Image {
                    id: saywhat
                    anchors.fill: parent
                    source: "images/saywhat.jpg"
                    fillMode: Image.PreserveAspectFit
                }

                Text {
                    id: movieNight
                    color: "#fc0909"
                    text: qsTr("It's Movie Night!")
                    anchors.top: parent.top
                    font.pixelSize: 20
                    anchors.topMargin: 0
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            Rectangle {
                id: bgTopRight
                color: "#00ffffff"
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredHeight: 200
                Layout.preferredWidth: 200

                Text {
                    id: whatText
                    text: qsTr("Say what movie should I watch")
                    anchors.top: parent.top
                    font.pixelSize: 20
                    fontSizeMode: Text.HorizontalFit
                    font.styleName: "Bold"
                    anchors.topMargin: 0
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    id: moreText
                    text: qsTr("more times!")
                    anchors.bottom: parent.bottom
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    fontSizeMode: Text.HorizontalFit
                    anchors.bottomMargin: 5
                }
            }

            Rectangle {
                id: bgBotLeft
                color: "#00ffffff"
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredHeight: 200
                Layout.preferredWidth: 200
            }

            Rectangle {
                id: bgBotRight
                color: "#00ffffff"
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredHeight: 200
                Layout.preferredWidth: 200

                Image {
                    id: bigSurprise
                    anchors.fill: parent
                    source: "images/BigSurprise.jpg"
                    fillMode: Image.PreserveAspectFit
                }
            }
        }
    }
}




/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
