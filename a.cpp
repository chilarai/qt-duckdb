#include <stdio.h>
#include <iostream>
#include "duckdb.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    duckdb::DuckDB db(nullptr);
    duckdb::Connection con(db);

    // create the table
    con.Query("CREATE TABLE people(id INTEGER, name VARCHAR)");

    // initialize the appender
    duckdb::Appender appender(con, "people");
    appender.AppendRow(1, "Mark");
    appender.AppendRow(2, "Hannes");
    appender.Close();

    auto result = con.Query("SELECT * FROM people");
    if (!result->success)
    {
        std::cout << result->error;
    }
    else
    {
        // no member named row_count
        idx_t a = result.row_count();
        for (idx_t i = a; i <= a; i++)
        {
            result->GetValue(1, i).Print();
        }
    }
    return 0;
}