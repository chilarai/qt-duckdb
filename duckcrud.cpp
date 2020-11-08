#include "duckcrud.h"

DuckCRUD::DuckCRUD(QObject *parent) : QObject(parent),
    db(nullptr), con(db), counter(1)
{

    // Create a table in constructor and insert some default values

    con.Query("CREATE TABLE people(id INTEGER, name VARCHAR)");
    con.Query("CREATE TABLE test");
    con.Query("INSERT INTO people VALUES (0,'Mark'), (1, 'Hannes')");
}

void DuckCRUD::insertData()
{
    // Increment the counter
    // append to the table and close the appender to add data to database
    // Read more here https://duckdb.org/docs/data/appender

    counter++;
    duckdb::Appender appender(con, "people");

    QString newData = "Test" + QString::number(counter);
    appender.AppendRow(counter, newData.toUtf8().constData());
    appender.Close();

    emit dataUpdated();
}


QStringList DuckCRUD::readTableData()
{

    QStringList output;

    auto result = con.Query("SELECT * FROM people");

    // If failed to fetch data from table
    if (!result->success){
        qDebug() << result->error.at(0);
        output << "NULL";
    }
    else{
        // Get the size of the collection
        // Get the result and convert standard string to QString
        // before inserting in QStringList

        idx_t a = result->collection.count;
        for (idx_t i = 0; i < a; i++){
            output << QString::fromStdString(result->GetValue(1, i).ToString());
        }
    }

    return output;
}

void DuckCRUD::updateData()
{
    // Update date using prepared statement

    QString name = "Replaced name" + QString::number(counter);
    auto prepared = con.Prepare("UPDATE people SET name = $1 WHERE id = $2");
    auto prep = prepared->Execute(name.toUtf8().constData(), counter);

    emit dataUpdated();
}

void DuckCRUD::deleteData()
{
    auto result = con.Query("DELETE FROM people WHERE id = " + QString::number(counter).toStdString());
    counter--;
    emit dataUpdated();
}

void DuckCRUD::processCsv()
{
    QElapsedTimer timer;
    timer.start();

    // I tested on Macbook Air Early 2015, i5, 4gb with 1.5GB file
    // It takes about 30 seconds
    auto result = con.Query("CREATE TABLE t1 AS SELECT * FROM read_csv_auto ('/Abosolute/Path/To/CSV/File.csv')");
    result->Print();

    qDebug() << "The slow operation took" << timer.elapsed() << "milliseconds";
}
