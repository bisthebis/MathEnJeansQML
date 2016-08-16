import QtQuick 2.4
import Math.Data 1.0

Page2Form {

    id: page2Form



    MathGridSolver {
        id: solver
        width: page1.sharedGridData.GameWidth
        height: page1.sharedGridData.GameHeight
        onWidthChanged: {console.log("gridoslver resized")}

        onSolvingCompleted: {

            page2Form.showSolutionButton.text = qsTr("Found " + solver.solutionsSize() + " solutions.")

        }

    }

    solveButton.onClicked: {solver.beginSolving();}

}
