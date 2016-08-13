var BlockComponent = null;
var BlockArray = null
var GameData;

function initGame()
{
    GameData = data;
    console.log(typeof GameData)
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
            dynObject.state = "checkedBlack"


            BlockArray[getIndex(i, j)] = dynObject;
        }
    }

}


function handleClick(x, y)
{
    console.log("shift at : " + x + ";" + y);
    console.log(typeof GameData)
    GameData.switchValue(x, y);
}
