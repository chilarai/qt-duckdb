#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtGlobal>
#include <QDebug>

#include "duckcrud.h"
#include "childcrud.h"


//duckdb::DuckDB DuckCRUD::db(nullptr);
//duckdb::Connection DuckCRUD::con(db);

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Initialize DuckCRUD object
    // And set context for QML
    DuckCRUD *duckCRUD = new DuckCRUD;
    ChildCRUD *childCRUD = new ChildCRUD(duckCRUD);

    engine.rootContext()->setContextProperty("DuckCRUD", duckCRUD);
    engine.rootContext()->setContextProperty("ChildCRUD", childCRUD);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
