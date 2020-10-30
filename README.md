# QT-DuckDB InMemory CRUD operations

This project demostrates how you can use the **Qt framework** to connect to [**DuckDB**](https://duckdb.org/).

DuckDB is an embeddable SQL OLAP database management system and comes in very handy to handle Analytical queries.

## Installation

This demo project will cover compilation on **Mac** only. However, it will not be very difficult to compile on other platforms. You just need to download the required binaries (linked libraries, eg, .dll, .so files) on the respective platforms.

You can find the required binaries here: https://duckdb.org/docs/installation/

**The following steps are already done inside the project. This is only required for fresh projects.** After downloading, you need to configure the following.

1. Copy the `libduckdb.dylib` & `duckdb.hpp` files in the Qt project root.

2. Adjust the `.pro` file to add the library. The following line needs to be added in the file for **Mac**

```
macx: LIBS += -L$$PWD/./ -lduckdb
```

The path can be adjusted in **-L\$\$PWD/./**.

For other platforms, you can easily follow the instructions on https://doc.qt.io/qtcreator/creator-project-qmake-libraries.html

3. Import `duckdb.hpp` file in the project

## Project details

The CRUD related functions are described in `DuckCRUD` class. All the methods are `Q_INVOKABLE methods` and called inside QML file (main.qml)

## Note:

Please feel free to modify the project if you think any meaningful feature can be added

## Links

1. https://duckdb.org/
