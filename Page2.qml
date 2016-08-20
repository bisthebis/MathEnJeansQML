import QtQuick 2.4
import Math.Data 1.0

Page2Form {

    id: page2Form
    property int solutionIndex: 0

    onSolutionIndexChanged: {
        currentIndexSpinBox.value = solutionIndex;
        currentIndexText.text = "Current index : " + solutionIndex;
    }

    currentIndexSpinBox.onValueChanged: {
        solutionIndex = currentIndexSpinBox.value;
    }

    function showProgress() {
        showSolutionButton.text = "Solving in progress... " + (100 * solver.getSolvingProgress()).toFixed(2) + "%.";
    }



    MathGridSolver {
        id: solver
        width: page1.sharedGridData.GameWidth
        height: page1.sharedGridData.GameHeight
        onWidthChanged: {console.log("gridsolver resized")}
        onHeightChanged: {console.log("gridsolver resized")}

        onSolvingCompleted: {

            page2Form.showSolutionButton.text = qsTr("Found " + solver.solutionsSize() + " solutions.")
            parent.solutionIndex = 0;
            currentIndexSpinBox.to = solver.solutionsSize();

        }

    }

    solveButton.onClicked: {solver.beginSolving(); showSolutionButton.text = "Busy solving...";}
    showSolutionButton.onClicked: {
        if (solver.solutionsSize() < 1)
        {
            console.warn("No solution");
            if (! solver.isSolving())
            {
                showSolutionButton.text = "No solution stored. Maybe you should click on \"solve\" button ?";
            }
            else
            {
                page2Form.showProgress();
            }

            return;

        }
        if (solutionIndex >= solver.solutionsSize()) //Prevents array ofverflow
        {
            solutionIndex = 0;
        }

        console.log("index : " + solutionIndex + ". Size : " + solver.solutionsSize());
        var solution = solver.solution(solutionIndex);
        page1.sharedGridData.copyFirstLine(solution);
        page1.sharedGridData.complete();

        solutionIndex++;
        if (solutionIndex > solver.solutionsSize())
            solutionIndex = 0;

    }



    Timer {
        repeat: true;
        running: true;
        interval: 500;
        onTriggered: {
            if (solver.isSolving())
            {
                page2Form.showProgress();
            }
        }
    }

}
