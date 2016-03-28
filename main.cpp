#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "UI.h"

int main(int argc, char *argv[])
{
    // Register UI class for access in QML
    qmlRegisterSingletonType<UI>("MyModule", 1, 0, "UI", UI::singleton_instance);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}
