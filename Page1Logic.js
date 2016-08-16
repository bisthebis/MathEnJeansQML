var BlockComponent = null;
var BlockArray = null

function initGame()
{
    data.setGameHeight(boardHeight);
    data.setGameWidth(boardWidth);
    initCanvas();
}

function initBlockComponent()
{
    BlockComponent = Qt.createComponent("Block.qml");

    console.assert(BlockComponent.status === Component.Ready);
    console.debug("Block component loaded.")
}

function initCanvas()
{

    var nColumn = data.GameWidth;
    var nRow = data.GameHeight;
    var blockWidth = gameCanvas.width / nColumn;
    var blockHeight = gameCanvas.height / nRow;
    var getIndex = function(x, y) {return x + y * nRow;}

    BlockArray = new Array(nColumn*nRow);

    //cleaning canvas
    for (var i = gameCanvas.children.length; i > 0 ; i--)
    {
        if(gameCanvas.children[i-1] !== null)
            gameCanvas.children[i-1].destroy()
    }
    BlockArray = null;
    BlockArray = new Array(nColumn*nRow);
    console.log("Done")


    for (var j = 0; j < nRow; j++)
    {
        for (var i = 0; i < nColumn; i++)
        {
            var dynObject = BlockComponent.createObject(gameCanvas);
            dynObject.width = blockWidth;
            dynObject.height = blockHeight;
            dynObject.x = blockWidth * i;
            dynObject.y = blockHeight * j;
            dynObject.xInGrid = i;
            dynObject.yInGrid = j;
            dynObject.state = "uncheckedWhite"


            BlockArray[getIndex(i, j)] = dynObject;
        }
    }

}


function handleClick(x, y)
{
    console.log("shift at : " + x + ";" + y);
    console.log("w, h in GameData : " + data.GameWidth + " x " + data.GameHeight)
    data.switchValue(x, y);
}

function getStateOf(x, y)
{
    var isChecked = data.safeValueAt(x, y);
    var isBlack = data.safeResultAt(x, y);
    // console.log("result at " + x + ";" + y +" : " + isBlack)
    if (isChecked && isBlack)
        return "checkedBlack"
    else if (isChecked && !isBlack)
        return "checkedWhite"
    else if (!isChecked && isBlack)
        return "uncheckedBlack"
    else if (!isChecked && !isBlack)
        return "uncheckedWhite"
}

function updateStates()
{
    var getIndex = function(x, y) {return x + y * data.GameHeight;}
    for (var j = 0; j < boardHeight; j++)
    {
        for (var i = 0; i < boardWidth; i++)
        {
            BlockArray[getIndex(i, j)].state = getStateOf(i, j);

        }
    }
}
