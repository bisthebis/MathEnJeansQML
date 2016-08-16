import QtQuick 2.7
import QtQuick.Dialogs 1.2

import Math.Data 1.0

import "Page1Logic.js" as JS

Page1Form {

    property alias sharedGridData: data

    Component.onCompleted: {
        JS.initBlockComponent();
        JS.initGame();


    }

    onBoardWidthChanged: {console.log("boardWith : " + boardWidth); JS.initGame();}
    onBoardHeightChanged: {console.log("boardHeight : " + boardHeight); JS.initGame();}

    signal gameObjectToggled(int xGame, int yGame);
    onGameObjectToggled: {JS.handleClick(xGame, yGame); JS.updateStates()}

    complete.onClicked: {data.complete();}
    restart.onClicked: {data.restart();}

    onWidthChanged: {JS.initCanvas(); JS.updateStates();}
    onHeightChanged: {JS.initCanvas(); JS.updateStates();}





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
