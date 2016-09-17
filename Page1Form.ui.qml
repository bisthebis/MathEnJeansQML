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



        Flickable {
            anchors.top: parent.top
            anchors.bottom: dimensionsLayout.top
            contentWidth: gameCanvas.width
            contentHeight: gameCanvas.height
            Item {
            id: gameCanvas
            //anchors.top: parent.parent.top
            //anchors.bottom: dimensionsLayout.top
            width: parent.parent.width
            height: parent.parent.height
            }
        }

        RowLayout {
            id: dimensionsLayout
            width: parent.width;
            anchors.bottom: buttonsLayout.top
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

        RowLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            id: buttonsLayout
            height: 30

            Button {
                id: complete
                text: qsTr("Complete from first line")

            }

            Button {
                id: restart
                text: qsTr("Restart")

            }
        }



    }
}
