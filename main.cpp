#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>

#include "qmlcppinterface.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QmlCppInterface interface;
    engine.rootContext()->setContextProperty("_cpp", &interface);

    return app.exec();
}
