import QtQuick 2.0

Circle {
    id: sendButton

    property int counter: 25
    property string userNum: "5"
    property Receiver target: null

    signal send(string value)
    signal numberInput(string value)
    onTargetChanged: send.connect(target.receive)


    MouseArea {
        anchors.fill: parent

        onClicked: {
            //counter--
            //parent.send(counter)

            userNum = numberInputField.text
            numberInput.connect(target.receive)
            parent.numberInput(userNum)

        }

        onPressed: parent.buttonColor = "red"
        onReleased: parent.buttonColor = "#08a225"
    }
}
