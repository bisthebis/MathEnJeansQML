#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTextStream>

#include "griddata.h"
#include "gridsolver.h"
#include "globals.h"

QTextStream& out()
{
    static QTextStream stream(stdout);
    return stream;
}


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    GridData test(nullptr, 4, 4);
    test.switchValue(1, 0);
    test.complete();
    test.printToStdout();


    QQmlApplicationEngine engine;
    GridSolver::globalEngine = &engine;
    qmlRegisterType<GridData>("Math.Data", 1, 0, "MathGrid");
    qmlRegisterType<GridSolver>("Math.Data", 1, 0, "MathGridSolver");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));//*/

    return app.exec();
}
