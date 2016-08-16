import QtQuick 2.4
import Math.Data 1.0

Page2Form {

    id: page2Form
    property int solutionIndex: 0



    MathGridSolver {
        id: solver
        width: page1.sharedGridData.GameWidth
        height: page1.sharedGridData.GameHeight
        onWidthChanged: {console.log("gridoslver resized")}

        onSolvingCompleted: {

            page2Form.showSolutionButton.text = qsTr("Found " + solver.solutionsSize() + " solutions.")
            parent.solutionIndex = 0;

        }

    }

    solveButton.onClicked: {solver.beginSolving();}
    showSolutionButton.onClicked: {
        console.log("index : " + solutionIndex + ". Size : " + solver.solutionsSize());
        var solution = solver.solution(4);
        page1.sharedGridData.copyFirstLine(solution);
        page1.sharedGridData.complete();

        solutionIndex++;
        if (solutionIndex > solver.solutionsSize())
            solutionIndex = 0;

    }

}
