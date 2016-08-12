import QtQuick 2.7

Page1Form {
    onBoardWidthChanged: {console.log(boardWidth);}
    onBoardHeightChanged: {console.log(boardHeight);}
}
