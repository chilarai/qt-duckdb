#ifndef DUCKCRUD_H
#define DUCKCRUD_H

#include <QObject>
#include <QDebug>

#include "duckdb.hpp"

class DuckCRUD : public QObject
{
    Q_OBJECT
public:
    explicit DuckCRUD(QObject *parent = nullptr);

    Q_INVOKABLE void insertData();
    Q_INVOKABLE QStringList readTableData();
    Q_INVOKABLE void updateData(int id);
    Q_INVOKABLE void deleteData(int id);

signals:

private:
    duckdb::DuckDB db;
    duckdb::Connection con;
    int counter;

};

#endif // DUCKCRUD_H
