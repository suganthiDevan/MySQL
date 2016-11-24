
#include <QCoreApplication>
#include <QApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QTableView>
#include <QAbstractItemView>
#include <QSqlQueryModel>
#include <QtGui>
#include <QtSql>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTableView* table = new QTableView();
        table->setWindowTitle("QTableView View Database with Model");

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("contacts1");
    db.setUserName("root");
    db.setPassword("admin");


    if (!db.open())
        qDebug() << "Not connected!";

   else{

        qDebug() << "Connected!";

        }


     QSqlQuery qry("SELECT * FROM addbook");
  QSqlQueryModel model;
     model.setQuery(qry);
     table->setModel(&model);

     table->show();
  qDebug() << "Error..:" << qry.lastError().text();
  qDebug() << "Database Closing..";

    return app.exec();
}



