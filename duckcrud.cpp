#include "duckcrud.h"

DuckCRUD::DuckCRUD(QObject *parent) : QObject(parent),
    db(nullptr), con(db), counter(1)
{

    // Create a table in constructor and insert some default values

    con.Query("CREATE TABLE people(id INTEGER, name VARCHAR)");
    con.Query("INSERT INTO people VALUES (0,'Mark'), (1, 'Hannes')");
}

void DuckCRUD::insertData()
{
    // Increment the counter
    // append to the table and close the appender to add data to database
    // Read more here https://duckdb.org/docs/data/appender

    counter++;
    duckdb::Appender appender(con, "people");
    appender.AppendRow(counter, "Test" + QString::number(counter));
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

void DuckCRUD::updateData(int id)
{
    // Update date using prepared statement

    QString name = "Replaced name" + QString::number(id);
    auto prepared = con.Prepare("UPDATE people SET name = ? WHERE id = ?");
    prepared->Execute(name, id);

    emit dataUpdated();
}

void DuckCRUD::deleteData(int id)
{
    auto result = con.Query("DELETE FROM people WHERE id = " + QString::number(id).toStdString());
    emit dataUpdated();
}
