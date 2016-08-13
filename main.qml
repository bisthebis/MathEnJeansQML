import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

import Math.Data 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {

        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Second")
        }
    }

    Grid {
        Component.onCompleted: {
            setGameWidth(3);
            setGameHeight(3);
            switchValue(0, 0);
            switchValue(2, 0);
            switchValue(1, 1);
            switchValue(0, 2);
            switchValue(2, 2);//*/
            //computeResult();
            if (correct())
                console.log("Working")
        }

        id: data
        onCorrectChanged: {console.log("Correct !");}
    }
}
