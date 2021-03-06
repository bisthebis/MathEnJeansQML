#include "gridsolver.h"
#include "griddata.h"

#include <exception>
#include <iostream>

QQmlApplicationEngine* GridSolver::globalEngine = nullptr;

GridSolver::GridSolver(QObject *parent) : QObject(parent)
{
    connect(this, &GridSolver::widthChanged, this, &GridSolver::cleanup);
    connect(this, &GridSolver::heightChanged, this, &GridSolver::cleanup);

    connect(&watcher, &QFutureWatcher<void>::finished, this, &GridSolver::storeSolution);
    connect(&watcher, &QFutureWatcher<void>::finished, this, &GridSolver::solvingCompleted);
}

void GridSolver::cleanup()
{
    firstLinesToTry.clear();
    _solutions.clear();
}

bool GridSolver::isCorrectFirstLine(const QVector<bool> & line, int w, int h)
{
    GridData grid(nullptr, w, h);
    grid.copyFirstLine(line);
    grid.complete();
    return grid.correct();

}

void GridSolver::beginSolving()
{
    try
    {
        firstLinesToTry.clear();
        firstLinesToTry.reserve(1 << wToSolve);
    }

    catch (...)
    {
        //std::cerr << memory_error.what() << std::endl;
        emit errorOnCompletion();
        return;
    }
    const unsigned long max = 1 << wToSolve;
    for (unsigned long src = 0; src < max; ++src)
    {
        QVector<bool> array;
        array.reserve(wToSolve);
        for (int x = 0; x < wToSolve; ++x)
        {
            array.push_back((src & (1 << x)) > 0);
        }
        firstLinesToTry.push_back(array);
    }

    correctFirstLines = QtConcurrent::filtered(firstLinesToTry, [this](const QVector<bool>& a){return GridSolver::isCorrectFirstLine(a, this->width(), this->height());});
    watcher.setFuture(correctFirstLines);


}

void GridSolver::storeSolution()
{
    _solutions = correctFirstLines.results();
}
