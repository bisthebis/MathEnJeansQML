import QtQuick 2.7
import QtQuick.Dialogs 1.2

import Math.Data 1.0

import "uiLogic.js" as JS

Page1Form {

    property alias sharedGridData: data

    onBoardWidthChanged: {console.log("boardWith : " + boardWidth); JS.initGame();}
    onBoardHeightChanged: {console.log("boardHeight : " + boardHeight); JS.initGame();}

    signal gameObjectToggled(int xGame, int yGame);
    onGameObjectToggled: {JS.handleClick(xGame, yGame); JS.updateStates()}

    complete.onClicked: {data.complete();}

    Component.onCompleted: {
        JS.initBlockComponent();
        JS.initGame();



    }



    data: MathGrid {
        id: data
        objectName: "sharedGridData"

        onCorrectChanged: {if (data.correct) {victory.visible = true;}}
        onResultChanged: {JS.updateStates()}


    }

    MessageDialog {
        id: victory;
        title: "Victory !"
        text: "Congrats, you have won"

    }
}
