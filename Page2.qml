import QtQuick 2.4
import Math.Data 1.0

Page2Form {

    id: page2Form
    property int solutionIndex: 0




    MathGridSolver {
        id: solver
        width: page1.sharedGridData.GameWidth
        height: page1.sharedGridData.GameHeight
        onWidthChanged: {console.log("gridsolver resized")}
        onHeightChanged: {console.log("gridsolver resized")}

        onSolvingCompleted: {

            page2Form.showSolutionButton.text = qsTr("Found " + solver.solutionsSize() + " solutions.")
            parent.solutionIndex = 0;

        }

    }

    solveButton.onClicked: {solver.beginSolving(); showSolutionButton.text = "Busy solving...";}
    showSolutionButton.onClicked: {
        if (solver.solutionsSize() < 1)
        {
            console.warn("No solution");
            showSolutionButton.text = "No solution ! Maybe click on solve ?";
            return;

        }

        console.log("index : " + solutionIndex + ". Size : " + solver.solutionsSize());
        var solution = solver.solution(solutionIndex);
        page1.sharedGridData.copyFirstLine(solution);
        page1.sharedGridData.complete();

        solutionIndex++;
        if (solutionIndex > solver.solutionsSize())
            solutionIndex = 0;

    }

}
