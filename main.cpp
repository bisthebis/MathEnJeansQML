#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTextStream>

#include "griddata.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    /*GridData grid;
    QTextStream(stdout) << grid.checked.size() << endl;
    grid.setValue(2, 2, true);//*/

    QQmlApplicationEngine engine;
    qmlRegisterType<GridData>("Math.Data", 1, 0, "MathGrid");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));//*/

    return app.exec();
}
