import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {

    property alias boardWidth: widthBox.value
    property alias boardHeight: heightBox.value


    ColumnLayout {
        id: columnLayout1
        anchors.fill: parent


        Rectangle {
            color: "red"
            id: item1
            width: parent.width
            anchors.top: parent.top
            anchors.bottom: dimensionsLayout.top
        }
        RowLayout {
            id: dimensionsLayout
            width: parent.width;
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30;

            SpinBox {
                id: widthBox

            }

            SpinBox {
                id: heightBox
            }
        }
    }
}
