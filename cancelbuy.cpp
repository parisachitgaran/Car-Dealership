#include "cancelbuy.h"
#include "ui_cancelbuy.h"

#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlError>
#include <QDebug>
#include<QMultiMap>
#include<QDate>
#include<QPushButton>
#include<QVBoxLayout>


Cancelbuy::Cancelbuy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cancelbuy)
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

Cancelbuy::~Cancelbuy()
{
    delete ui;
}



//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//   tople with this ID from Sale table Delete and
//   "Existing" Car become 0 .

void Cancelbuy::on_pushButton_Save_clicked()
{
     QSqlQuery query1,query2;
     query1.prepare("DELETE FROM Customer "
                    "WHERE ID='"+ui->lineEdit_CuID->text() +"'");

     if(!query1.exec()){
                      qDebug() << query1.lastError().text() << query1.lastQuery();
                      QMessageBox::warning(this , "Delete Customer","Delete from Customer & Sale Table is failed !");

                  }
           else{
                      qDebug() << "else "<< query1.lastQuery();
                      QMessageBox::information(this , "Delete Customer","Delete from Customer & Sale Table is successfully .");



             }

     query2.prepare("UPDATE Car set Existing=1 "
                    "WHERE ID='"+ ui->lineEdit_CarID->text() +"' ");


     if(!query2.exec()){
                      qDebug() << query2.lastError().text() << query2.lastQuery();
                       QMessageBox::warning(this , "Update Car","Update Car Table is failed !");

                  }
           else{
                      qDebug() << "else "<< query2.lastQuery();
                      QMessageBox::information(this , "Update Car","Update Car Table is successfully .");

              }
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void Cancelbuy::on_pushButton_cancel_clicked()
{
    close();
}

