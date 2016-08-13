#ifndef GRIDSOLVER_H
#define GRIDSOLVER_H

#include <QObject>
#include <QtConcurrent>
#include "griddata.h"

class GridSolver : public QObject
{
    Q_OBJECT

    public:
        explicit GridSolver(QObject *parent = 0);

    signals:

    public slots:


    private:
        int wToSolve; //Size of the grid solutions to generate
        int hToSolve;
        QFutureWatcher<void> watcher;
        QList<QBitArray> firstLinesToTry;
        QFuture<QBitArray> correctFirstLines;
};

#endif // GRIDSOLVER_H
