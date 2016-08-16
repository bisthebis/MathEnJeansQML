#ifndef GRIDSOLVER_H
#define GRIDSOLVER_H

#include <QObject>
#include <QtConcurrent>
#include "griddata.h"
#include <QQmlApplicationEngine>
#include <QQmlComponent>



class GridSolver : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int width READ width WRITE setwidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setheight NOTIFY heightChanged)



    public:
        explicit GridSolver(QObject *parent = 0);

        static bool isCorrectFirstLine(const QList<bool>&, int w, int h); //filter function

        static QQmlApplicationEngine* globalEngine; //Global variable;

    signals:
        void widthChanged();
        void heightChanged();

        void solvingCompleted();

    public slots:
        void setwidth(int x) {wToSolve = x; emit widthChanged();}
        void setheight(int y) {hToSolve = y; emit heightChanged();}
        void cleanup();
        int width() const {return wToSolve;}
        int height() const {return hToSolve;}
        QList<bool> solution(const int i) const {return _solutions[i];}

        void beginSolving();
        void storeSolution();

        void setFirstSolution(GridData& target) {if(_solutions.empty()) return;  target.copyFirstLine(_solutions.first()); target.complete();}
        void setFirstSolutionStr(const QString& name) {
            //QQmlComponent component(globalEngine);
            //QObject* MyObject = component.create();

            GridData & target =  *globalEngine->rootObjects().first()->findChild<GridData*>(name);
            target.copyFirstLine(_solutions.first());
            target.complete();}

        int solutionsSize() const {return _solutions.size();}

    private:
        int wToSolve; //Size of the grid solutions to generate
        int hToSolve;
        QFutureWatcher<void> watcher;
        QList<QList<bool>> firstLinesToTry;
        QFuture<QList<bool>> correctFirstLines;
        QList<QList<bool>> _solutions;


};

#endif // GRIDSOLVER_H
