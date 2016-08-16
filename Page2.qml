import QtQuick 2.4
import Math.Data 1.0

Page2Form {



    MathGridSolver {
        id: solver
        width: page1.sharedGridData.GameWidth
        height: page1.sharedGridData.GameHeight
        onWidthChanged: {console.log("gridoslver resized")}

        onSolvingCompleted: {
            console.log("Solutions found : " + solver.solutionsSize());
            solver.setFirstSolutionStr("sharedGridData");

        }

    }

    solveButton.onClicked: {solver.beginSolving();}

}
