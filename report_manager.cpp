#include "report_manager.h"
#include "ui_report_manager.h"

#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlError>
#include <QDebug>
#include<QMultiMap>
#include<QDate>



Report_manager::Report_manager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Report_manager)
{
    ui->setupUi(this);

    // connect Database
   ////////////////////////////////////////////////////////////////////////

   QString servername = "DESKTOP-32NMLJN\\SQLEXPRESS";
             QString dbname = "CarDealership";
            QSqlDatabase Database = QSqlDatabase ::addDatabase("QODBC");
             qDebug () << "ODBC driver valid?" << Database.isValid ();
             Database.setConnectOptions();

             QString dsn = QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;") .arg(servername).arg(dbname);
             Database.setDatabaseName(dsn);

             if (Database.open()){
                 qDebug()<<"opened!";
                 //Database.close();
             }
             else{
                 qDebug()<<"Error ="<<Database.lastError();
             }


}

Report_manager::~Report_manager()
{
    delete ui;
}


void Report_manager::on_pushButton_show_clicked()
{
     QSqlQuery query1;
     QString Q;


     query1.prepare("SELECT * FROM Managers ORDER BY Lname ASC");


     if(query1.exec()){

         QSqlQueryModel *n=new QSqlQueryModel ;
           n->setQuery(query1);
           ui ->tableView_ReMgr->setModel(n);




     }

     else{
         QMessageBox::information(this , "Report","Report was not available");

      }

}


void Report_manager::on_pushButton_close_clicked()
{
    close();
}

