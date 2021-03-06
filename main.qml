import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

import Math.Data 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Sens dessus-dessous")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
            id: page1


        }

        Page2 {
            id: page2


        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("Game")
        }
        TabButton {
            text: qsTr("Options")
        }
    }


}
