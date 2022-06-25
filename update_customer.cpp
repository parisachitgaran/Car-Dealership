#include "update_customer.h"
#include "ui_update_customer.h"

#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlError>
#include <QDebug>
#include<QMultiMap>
#include<QDate>




Update_customer::Update_customer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Update_customer)
{
    ui->setupUi(this);




    ui->lineEdit_cuAlley->setEnabled(false);
    ui->lineEdit_cuFathername->setEnabled(false);
    ui->radioButton_f_cu->setEnabled(false);
    ui->radioButton_m_cu->setEnabled(false);
    ui->lineEdit_cuFname->setEnabled(false);
    ui->dateEdit_cuBdate->setEnabled(false);
    ui->lineEdit_cuLname->setEnabled(false);
    ui->lineEdit_cuMobile->setEnabled(false);
    ui->lineEdit_cuNationalID->setEnabled(false);
    ui->lineEdit_cuPlaque->setEnabled(false);
    ui->lineEdit_cuStreet->setEnabled(false);
    ui->lineEdit_phone_cu->setEnabled(false);



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

Update_customer::~Update_customer()
{
    delete ui;
}

void Update_customer::on_searchIDcu_clicked()
{
    QString cuID=ui->lineEdit_cuID->text();

    QSqlQuery query1,query2;
         query1.exec("SELECT ID FROM Customer WHERE ID='"+cuID+"' ");

         if(query1.first()){
              QMessageBox::information(this , "inquiry Customer","This Customer is Existing");

                   query2.exec("SELECT * FROM Customer WHERE ID='"+cuID+"' ");
                   QSqlQueryModel *n=new QSqlQueryModel;
                     n->setQuery(query2);
                     ui ->tableView_informationcu->setModel(n);


                     ui->lineEdit_cuAlley->setEnabled(true);
                     ui->lineEdit_cuFathername->setEnabled(true);
                     ui->radioButton_f_cu->setEnabled(true);
                     ui->radioButton_m_cu->setEnabled(true);
                     ui->lineEdit_cuFname->setEnabled(true);
                     ui->dateEdit_cuBdate->setEnabled(true);
                     ui->lineEdit_cuLname->setEnabled(true);
                     ui->lineEdit_cuMobile->setEnabled(true);
                     ui->lineEdit_cuNationalID->setEnabled(true);
                     ui->lineEdit_cuPlaque->setEnabled(true);
                     ui->lineEdit_cuStreet->setEnabled(true);
                     ui->lineEdit_phone_cu->setEnabled(true);



         }

         else{
             QMessageBox::information(this , "inquiry Customer","This Customer is  not Existing");

          }
}


void Update_customer::on_btn_save_updatecustomer_clicked()
{
    QSqlQuery q,q1,query1;

   QDate d=ui->dateEdit_cuBdate->date();


   if(ui->lineEdit_cuFname->text().length()>0)
            q.exec("UPDATE Customer set Fname='"+ ui->lineEdit_cuFname->text() +"' WHERE ID='"+ ui->lineEdit_cuID->text() +"' ");

   if(ui->lineEdit_cuLname->text().length()>0)
            q.exec("UPDATE Customer set Lname='"+ ui->lineEdit_cuLname->text() +"' WHERE ID='"+ ui->lineEdit_cuID->text() +"' ");

   if(ui->lineEdit_cuFathername->text().length()>0)
            q.exec("UPDATE Customer set FatherName='"+ ui->lineEdit_cuFathername->text() +"' WHERE ID='"+ ui->lineEdit_cuID->text() +"' ");


   if(ui->radioButton_f_cu->isChecked()){
            q.prepare("UPDATE Customer set Sex=0  WHERE ID='"+ ui->lineEdit_cuID->text() +"' ");
            q.exec();
   }
   if(ui->radioButton_m_cu->isChecked()){
            q.prepare("UPDATE Customer set Sex=1  WHERE ID='"+ ui->lineEdit_cuID->text() +"' ");
            q.exec();
   }

   if(ui->lineEdit_cuNationalID->text().length()>0)
            q.exec("UPDATE Customer set NationalID='"+ ui->lineEdit_cuNationalID->text() +"' WHERE ID='"+ ui->lineEdit_cuID->text() +"' ");

   if(ui->lineEdit_phone_cu->text().length()>0)
            q.exec("UPDATE Customer set Phone='"+ ui->lineEdit_phone_cu->text() +"' WHERE ID='"+ ui->lineEdit_cuID->text() +"' ");

   if(ui->lineEdit_cuMobile->text().length()>0)
            q.exec("UPDATE Customer set Mobile='"+ ui->lineEdit_cuMobile->text() +"' WHERE ID='"+ ui->lineEdit_cuID->text() +"' ");

   if(ui->lineEdit_cuStreet->text().length()>0)
            q.exec("UPDATE Customer set Street='"+ ui->lineEdit_cuStreet->text() +"' WHERE ID='"+ ui->lineEdit_cuID->text() +"' ");

   if(ui->lineEdit_cuAlley->text().length()>0)
            q.exec("UPDATE Customer set Alley='"+ ui->lineEdit_cuAlley->text() +"' WHERE ID='"+ ui->lineEdit_cuID->text() +"' ");

   if(ui->lineEdit_cuPlaque->text().length()>0)
            q.exec("UPDATE Customer set Plaque='"+ ui->lineEdit_cuPlaque->text() +"' WHERE ID='"+ ui->lineEdit_cuID->text() +"' ");


    q1.exec("UPDATE Customer set BDate='"+QString::number(d.year())+"-"+QString::number(d.month())+"-"+QString::number(d.day())+"' WHERE ID='"+ ui->lineEdit_cuID->text() +"' ");



    query1.exec("SELECT * FROM Customer WHERE ID="+ui->lineEdit_cuID->text()+"");


    if(query1.first()){

        QSqlQueryModel *n=new QSqlQueryModel ;
          n->setQuery(query1);
          ui ->tableView_informationcu->setModel(n);

    }



}


void Update_customer::on_btn_save_updatecustomer_2_clicked()
{
    close();
}

