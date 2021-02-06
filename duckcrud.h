// ===============================================
// DuckCRUD
// Sample implementation of CRUD with DuckDB & QT
// ===============================================

#ifndef DUCKCRUD_H
#define DUCKCRUD_H

#include <QObject>
#include <QElapsedTimer>
#include <QDebug>

#include "duckdb.hpp"

class DuckCRUD : public QObject
{
    Q_OBJECT
public:
    explicit DuckCRUD(QObject *parent = nullptr);

    Q_INVOKABLE void insertData();
    Q_INVOKABLE QStringList readTableData();
    Q_INVOKABLE void updateData();
    Q_INVOKABLE void deleteData();

    // Process Bulk data
    Q_INVOKABLE void processCsv();

    // Vars
    //    static duckdb::DuckDB db;
    //    static duckdb::Connection con;
    duckdb::DuckDB db;
    duckdb::Connection con;
    int counter;

signals:
    void dataUpdated();
    void csvReadComplete(QString time);

private:



};

#endif // DUCKCRUD_H
