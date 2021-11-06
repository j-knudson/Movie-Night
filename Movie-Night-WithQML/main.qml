import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0


//import Monty 1.0
import Comms 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Happy Belated Movie Night from John Knudson and Jacob Klockenga")

    /*SomeClass {
        id: myClass
    }*/

    //QML Signal
    signal userNumber(string text)

    //QML Slot
    function qmlMovieUpdate(newTitle){
        movieTitleText.text=newTitle
    }
    property int counter: 0;

    CFantasyMovies {
        id: movies
    }

    Connections {

        target: movies
        //function onMovieTitleChanged(getMovieTitle) {movieTitleText.text = getMovieTitle}
        onMovieTitleChanged: {

            //movieTitleText.text  = counter+movies.getUserRandomNumber();
            //counter++;
            //movieTitleText.text = movies.getMovieTitle();
            //movieTitleText.text = counter+movies.getMovieTitle();
            counterText.text = 10-counter;
        }
        onUserRandomNumberChanged: {

            //movies.setMovieTitle("This will be a movie "+movies.getUserRandomNumber())
            counter++;
            //movieTitleText.text  = counter+" "+movies.getUserRandomNumber();
            //movieTitleText.text  = counter+" "+movies.getMovieTitle();
        }
    }

    BackgroundForm {
        id: backgroundForm
        anchors.fill: parent
    }


    GridLayout {
        anchors.fill: parent
        rowSpacing: 2
        columnSpacing: 2
        rows: 1
        columns: 2

        Rectangle {
            id: topLeft
            color: "#00ffffff"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            Layout.preferredWidth: 200
        }

        Rectangle {
            id: topRight
            color: "#00ffffff"
            Layout.preferredWidth: 200
            Layout.fillHeight: true
            Layout.preferredHeight: 200
            Layout.fillWidth: true

            Image {
                id: popcorn
                anchors.fill: parent
                source: "images/popcorn.png"
                scale: 0.75
                fillMode: Image.PreserveAspectFit

                Text {
                    id: counterText
                    width: 124
                    height: 96
                    color: "#2252e7"
                    text: qsTr("N/A")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 45
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignTop
                    font.weight: Font.ExtraBold
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

        Rectangle {
            id: botLeft
            color: "#00ffffff"
            Layout.preferredWidth: 200
            Layout.fillHeight: true
            Layout.preferredHeight: 200
            Layout.fillWidth: true


            Rectangle {
                id: rectangle
                color: "#00ffffff"
                border.width: 0
                anchors.fill: parent

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
                        //text: myClass.someVar
                        overwriteMode: true



                    }
                }

                Rectangle {
                    id: instructionsRect
                    color: "#00ffffff"
                    border.width: 0
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.rightMargin: 319
                    anchors.leftMargin: 0
                    anchors.topMargin: 0

                    Text {
                        id: instuctionsText
                        color: "#fcfafa"
                        text: qsTr("1.) Enter Number 2.) Press Green Button")
                        anchors.fill: parent
                        font.pixelSize: 20
                        fontSizeMode: Text.HorizontalFit
                    }
                }
            }

            Rectangle {
                id: buttonRec
                color: "#158f08"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.topMargin: 79
                anchors.rightMargin: -2
                anchors.leftMargin: 2
                anchors.bottomMargin: 0



                Text {
                    id: getMovieButtonText
                    color: "#fcf9f9"
                    text: qsTr("What Movie should I watch? ")
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.right: parent.right
                    font.pixelSize: 24
                    horizontalAlignment: Text.AlignHCenter
                    fontSizeMode: Text.HorizontalFit
                    font.bold: true
                    anchors.rightMargin: 0
                    anchors.leftMargin: 0
                }

                MouseArea {
                    id: getMovieButtonMouseArea
                    anchors.fill: parent
                    //connections:
                    onClicked: {
                        //movies.setMovieTitle("My First Movie")
                        //movies.setMovieTitle(numberInputField.text)
                        //movies.callMe()
                        //movies.setUserRandomNumber("Test")
                        //numberInputField.text = movies.getUserRandomNumber()
                        movies.setUserRandomNumber(numberInputField.text)

                        //QML Signal
                        userNumber(numberInputField.text)

                    }
                }
            }
            Button {
                id: exit
                y: 206
                width: 66
                height: 33
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.leftMargin: 2
                anchors.bottomMargin: 0
                text: qsTr("Exit")
                onClicked: Qt.quit();

            }
        }

        Rectangle {
            id: botRight
            color: "#00ffffff"
            Layout.preferredWidth: 200
            Layout.fillHeight: true
            Layout.preferredHeight: 200
            Layout.fillWidth: true

            TextField {
                id: movieTitleText
                //text: qsTr("Insert Movie Here")
                text: movies.getMovieTitle()
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.bottomMargin: 2
            }
        }

    }
}

