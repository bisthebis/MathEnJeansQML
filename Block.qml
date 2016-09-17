import QtQuick 2.0



Item {

    property int xInGrid: -1 //Must be changed in JS
    property int yInGrid: -1 //Must be changed in JS

    signal clicked;
    onClicked: { page1.gameObjectToggled(xInGrid, yInGrid);}

    id: block;

    Image {
        id: resultPic;
        fillMode: Image.Stretch
        source: "assets/resultWhite.png"
        anchors.fill: parent

    }

    Image {
        id: checkedPic
        fillMode: Image.Stretch
        source: "assets/checked.png"
        anchors.centerIn: resultPic
        width: resultPic.width / 2
        height: resultPic.height / 2
        visible: false
    }

    state: "uncheckedWhite"
    states: [
        State {
            name: "uncheckedWhite"

        },

        State {
            name: "uncheckedBlack"
            PropertyChanges {
                target: resultPic; source:"assets/resultBlack.png";

            }
        },

        State {
            name: "checkedWhite"
            PropertyChanges {
                target: checkedPic; visible: true;

            }
        },

        State {
            name: "checkedBlack"
            PropertyChanges {
                target: checkedPic; visible: true;

            }
            PropertyChanges {
                target: resultPic;
                source: "assets/resultBlack.png"
            }
        }


    ]


    MouseArea {
        onClicked: parent.clicked()
        anchors.fill: parent
    }

}
