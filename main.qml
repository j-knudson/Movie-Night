import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 2.0


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    BackgroundForm {
        id: backgroundForm
        anchors.fill: parent

        Receiver {
            id: receiver
            x: 427
            y: 53
            opacity: 1
            visible: true
            buttonColor: "#000813a2"
        }

        Rectangle {
            id: botLeft
            y: 240
            width: 321
            height: 240
            color: "#00ffffff"
            border.color: "#e31156"
            border.width: 0
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.leftMargin: 0
            anchors.bottomMargin: 0

            Sender {
                id: sender
                buttonColor: "#0e7f08"
                displayText: "What movie should I watch?"
                target: receiver
                anchors.fill: parent
                anchors.topMargin: 80
            }

            Rectangle {
                id: rectangle
                y: 0
                width: 321
                height: 80
                color: "#00ffffff"
                border.width: 0
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 160
                anchors.leftMargin: 0

                Rectangle {
                    id: inputRect
                    color: "#00ffffff"
                    border.width: 0
                    anchors.fill: parent
                    anchors.topMargin: 38

                    TextField {
                        id: numberInputField
                        x: 8
                        y: 14
                        width: 305
                        height: 20
                        color: "#0b9021"
                        anchors.fill: parent
                        font.pixelSize: 20
                        anchors.rightMargin: 0
                        anchors.leftMargin: 0
                        anchors.topMargin: -10
                        anchors.bottomMargin: 0
                        placeholderText: qsTr("Enter number here")
                        overwriteMode: true



                    }
                }

                Rectangle {
                    id: instructionsRect
                    color: "#00ffffff"
                    border.width: 0
                    anchors.top: parent.top
                    anchors.topMargin: 0

                    Text {
                        id: instuctionsText
                        color: "#fcfafa"
                        text: qsTr("1.) Enter Number 2.) Press Green Button")
                        anchors.fill: parent
                        font.pixelSize: 20
                    }
                }
            }
        }

        Rectangle {
            id: botRightRec
            x: 319
            y: 265
            width: 321
            height: 215
            color: "#00ffffff"
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 0
            anchors.bottomMargin: 0

            Text {
                id: movieText
                x: 0
                y: 143
                width: 321
                height: 40
                color: "#fbf7f7"
                text: qsTr("Surprise Movie:")
                anchors.bottom: parent.verticalCenter
                font.pixelSize: 30
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                fontSizeMode: Text.HorizontalFit
                font.bold: true
                anchors.bottomMargin: -75
            }

            Rectangle {
                id: movieTitleReceiver
                x: 0
                y: 177
                width: 321
                height: 38
                color: "#ffffff"
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0

                Text {
                    id: movieTitle
                    text: qsTr("Insert title here")
                    anchors.fill: parent
                    font.pixelSize: 15
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    fontSizeMode: Text.HorizontalFit
                }
            }
        }


    }
}
