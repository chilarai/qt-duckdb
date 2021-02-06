#include "childcrud.h"

ChildCRUD::ChildCRUD(QObject *parent) : QObject(parent)
{

}

ChildCRUD::ChildCRUD(DuckCRUD *duckCrud, QObject *parent)
{

   this->out = duckCrud->readTableData();
}

void ChildCRUD::callChild()
{
    qDebug() << this->out;
}
