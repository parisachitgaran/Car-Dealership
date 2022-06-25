#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlError>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QString servername = "DESKTOP-32NMLJN\\SQLEXPRESS";
              QString dbname = "CarDealership";
             QSqlDatabase Database = QSqlDatabase ::addDatabase("QODBC");
              qDebug () << "ODBC driver valid?" << Database.isValid ();
              Database.setConnectOptions();

              QString dsn = QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;") .arg(servername).arg(dbname);
              Database.setDatabaseName(dsn);

              if (Database.open()){
                  qDebug()<<"opened!";

              }
              else{
                  qDebug()<<"Error ="<<Database.lastError();
              }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_OK_clicked()
{

    QString username=ui->lineEdit_username->text();

    if(username=="user"){
        int id;
          QSqlQuery query1;

         query1.exec("SELECT NationalID FROM Managers WHERE NationalID='"+ui->lineEdit_password->text()+"' ");


          if (query1.first())
          {
           id= query1.value(0).toInt();

           QMessageBox::information(this, "Login","       Welcome       ");
           hide();

           Menu = new menu(this);
           Menu ->show();

          }
          else {
           QMessageBox::warning(this, "Login","Password is not Correct");

          }
    }
    else{
       QMessageBox::warning(this, "Login","user name is not Correct");
    }



}









