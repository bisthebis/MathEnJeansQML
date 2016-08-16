import QtQuick 2.5
import QtQuick.Controls 2.0

Item {
    id: item1
    width: 400
    height: 400
    property alias currentIndexSpinBox: currentIndexSpinBox
    property alias currentIndexText: currentIndexText
    property alias showSolutionButton: showSolutionButton
    property alias solveButton: solveButton

    Column {
        id: column1
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width/3


        Button {
            id: solveButton
            text: qsTr("Solve")
            width: parent.width

        }

        Button {
            id: showSolutionButton
            text: qsTr("No solutions yet")
            width: parent.width

        }

        Text {
            id: currentIndexText
            text: "Current index : 0"

        }

        SpinBox {
            id: currentIndexSpinBox
            to: 1

        }
    }
}
