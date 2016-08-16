import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0


Item {

    property alias boardWidth: widthBox.value
    property alias boardHeight: heightBox.value
    property alias gameCanvas: gameCanvas
    property alias complete: complete
    property alias restart: restart



    ColumnLayout {
        id: columnLayout1
        anchors.fill: parent



        Item {
            id: gameCanvas
            anchors.top: parent.top
            anchors.bottom: dimensionsLayout.top
            width: parent.width

        }

        RowLayout {
            id: dimensionsLayout
            width: parent.width;
            anchors.bottom: complete.top
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30;

            SpinBox {
                id: widthBox
                value: 6

            }

            SpinBox {
                id: heightBox
                value: 6
            }
        }

        Button {
            id: complete
            text: qsTr("Complete from first line")
            anchors.horizontalCenter: dimensionsLayout.horizontalCenter
            height: 50
            anchors.bottom: restart.top

        }

        Button {
            id: restart
            text: qsTr("Restart")
            anchors.bottom: parent.bottom
            height: 50;
            anchors.horizontalCenter: dimensionsLayout.horizontalCenter
        }



    }
}
