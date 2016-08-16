#include "gridsolver.h"
#include "griddata.h"

QQmlApplicationEngine* GridSolver::globalEngine = nullptr;

GridSolver::GridSolver(QObject *parent) : QObject(parent)
{
    connect(&watcher, &QFutureWatcher<void>::finished, this, &GridSolver::storeSolution);
    connect(&watcher, &QFutureWatcher<void>::finished, this, &GridSolver::solvingCompleted);
}

bool GridSolver::isCorrectFirstLine(const QList<bool> & line, int w, int h)
{
    GridData grid(nullptr, w, h);
    grid.copyFirstLine(line);
    grid.complete();
    return grid.correct();

}

void GridSolver::beginSolving()
{
    firstLinesToTry.clear();
    firstLinesToTry.reserve(1 << wToSolve);
    const unsigned long max = 1 << wToSolve;
    for (unsigned long i = 0; i < max; ++i)
    {
        QList<bool> array;
        array.reserve(wToSolve);
        for (int x = 0; x < wToSolve; ++x)
        {
            array.push_back((max & (1 << x)) > 0);
        }
        firstLinesToTry.push_back(array);
    }

    correctFirstLines = QtConcurrent::filtered(firstLinesToTry, [this](const QList<bool>& a){return GridSolver::isCorrectFirstLine(a, this->width(), this->height());});
    watcher.setFuture(correctFirstLines);

}

void GridSolver::storeSolution()
{
    _solutions = correctFirstLines.results();
}
