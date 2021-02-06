// ================================================
// ChildCRUD
// Child class calling the DuckCRUD object instance
// ================================================

#ifndef CHILDCRUD_H
#define CHILDCRUD_H

#include <QObject>
#include "duckcrud.h"

class ChildCRUD : public QObject
{
    Q_OBJECT
    QStringList out;

public:
    explicit ChildCRUD(QObject *parent = nullptr);
    explicit ChildCRUD(DuckCRUD *duckCrud, QObject *parent = nullptr);

    Q_INVOKABLE void callChild();

signals:

};

#endif // CHILDCRUD_H
