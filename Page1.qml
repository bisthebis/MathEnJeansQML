import QtQuick 2.7

import Math.Data 1.0

import "uiLogic.js" as JS

Page1Form {
    onBoardWidthChanged: {console.log("boardWith : " + boardWidth); JS.initGame();}
    onBoardHeightChanged: {console.log("boardHeight : " + boardHeight); JS.initGame();}

    signal gameObjectToggled(int xGame, int yGame, Block sender);
    onGameObjectToggled: {console.log(xGame + ";" + yGame); JS.handleClick(xGame, yGame); JS.updateStates()}

    Component.onCompleted: {
        JS.initBlockComponent();
        JS.initGame();


    }



    MathGrid {
        id: data
        onCorrectChanged: {console.log("Correct !");}
        onResultChanged: {console.log("Result changed")}
    }
}
