#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTextStream>

#include "griddata.h"
#include "gridsolver.h"



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;
    GridSolver::globalEngine = &engine;
    qmlRegisterType<GridData>("Math.Data", 1, 0, "MathGrid");
    qmlRegisterType<GridSolver>("Math.Data", 1, 0, "MathGridSolver");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));//*/

    return app.exec();
}
