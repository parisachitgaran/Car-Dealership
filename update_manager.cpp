#include "update_manager.h"
#include "ui_update_manager.h"

#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlError>
#include <QDebug>
#include<QMultiMap>
#include<QDate>


Update_manager::Update_manager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Update_manager)
{
    ui->setupUi(this);


    // ui->btn_save->setEnabled(false);

    ui->lineEdit_mgrAlley->setEnabled(false);
    ui->lineEdit_mgrFathername->setEnabled(false);
    ui->radioButton_f_mgr->setEnabled(false);
    ui->radioButton_m_mgr->setEnabled(false);
    ui->lineEdit_mgrFname->setEnabled(false);
    ui->dateEdit_mgrBdate->setEnabled(false);
    ui->lineEdit_mgrLname->setEnabled(false);
    ui->lineEdit_mgrMobile->setEnabled(false);
    ui->lineEdit_mgrNationalID->setEnabled(false);
    ui->lineEdit_mgrPlaque->setEnabled(false);
    ui->lineEdit_mgrStreet->setEnabled(false);
    ui->lineEdit_phone_mgr->setEnabled(false);



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

Update_manager::~Update_manager()
{
    delete ui;
}


//////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////

void Update_manager::on_searchIDmgr_clicked()
{
    QString mgrID=ui->lineEdit_mgrID->text();

    QSqlQuery query1,query2;
         query1.exec("SELECT ID FROM Managers WHERE ID='"+mgrID+"' ");

         if(query1.first()){
              QMessageBox::information(this , "inquiry Manager","This Mansger is Existing");

                   query2.exec("SELECT * FROM Managers WHERE ID='"+mgrID+"' ");
                   QSqlQueryModel *n=new QSqlQueryModel;
                     n->setQuery(query2);
                     ui ->tableView_mgr->setModel(n);


                     ui->lineEdit_mgrAlley->setEnabled(true);
                     ui->lineEdit_mgrFathername->setEnabled(true);
                     ui->radioButton_f_mgr->setEnabled(true);
                     ui->radioButton_m_mgr->setEnabled(true);
                     ui->lineEdit_mgrFname->setEnabled(true);
                     ui->dateEdit_mgrBdate->setEnabled(true);
                     ui->lineEdit_mgrLname->setEnabled(true);
                     ui->lineEdit_mgrMobile->setEnabled(true);
                     ui->lineEdit_mgrNationalID->setEnabled(true);
                     ui->lineEdit_mgrPlaque->setEnabled(true);
                     ui->lineEdit_mgrStreet->setEnabled(true);
                     ui->lineEdit_phone_mgr->setEnabled(true);


         }

         else{
             QMessageBox::information(this , "inquiry Manager","This Mansger is  not Existing");

          }
}

//////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////


void Update_manager::on_btn_save_updatemanager_clicked()
{
    QSqlQuery q,q1,query1;

    QDate d=ui->dateEdit_mgrBdate->date();


   if(ui->lineEdit_mgrFname->text().length() >0)
            q.exec("UPDATE Managers set Fname='"+ ui->lineEdit_mgrFname->text() +"' WHERE ID='"+ ui->lineEdit_mgrID->text() +"' ");

   if(ui->lineEdit_mgrLname->text().length()>0)
            q.exec("UPDATE Managers set Lname='"+ ui->lineEdit_mgrLname->text() +"' WHERE ID='"+ ui->lineEdit_mgrID->text() +"' ");

   if(ui->lineEdit_mgrFathername->text().length()>0)
            q.exec("UPDATE Managers set FatherName='"+ ui->lineEdit_mgrFathername->text() +"' WHERE ID='"+ ui->lineEdit_mgrID->text() +"' ");

   if(ui->radioButton_f_mgr->isChecked())
   {     q.prepare("UPDATE Managers set Sex=0  WHERE ID="+ ui->lineEdit_mgrID->text() +" ");
       q.exec();
   }
   if(ui->radioButton_m_mgr->isChecked())
   {     q.prepare("UPDATE Managers set Sex=1  WHERE ID="+ ui->lineEdit_mgrID->text() +" ");
         q.exec();
    }
   if(ui->lineEdit_mgrNationalID->text().length()>0)
            q.exec("UPDATE Managers set NationalID='"+ ui->lineEdit_mgrNationalID->text() +"' WHERE ID='"+ ui->lineEdit_mgrID->text() +"' ");

   if(ui->lineEdit_phone_mgr->text().length()>0)
            q.exec("UPDATE Managers set Phone='"+ ui->lineEdit_phone_mgr->text() +"' WHERE ID='"+ ui->lineEdit_mgrID->text() +"' ");

   if(ui->lineEdit_mgrMobile->text().length()>0)
            q.exec("UPDATE Managers set Mobile='"+ ui->lineEdit_mgrMobile->text() +"' WHERE ID='"+ ui->lineEdit_mgrID->text() +"' ");

   if(ui->lineEdit_mgrStreet->text().length()>0)
            q.exec("UPDATE Managers set Street='"+ ui->lineEdit_mgrStreet->text() +"' WHERE ID='"+ ui->lineEdit_mgrID->text() +"' ");

   if(ui->lineEdit_mgrAlley->text().length()>0)
            q.exec("UPDATE Managers set Alley='"+ ui->lineEdit_mgrAlley->text() +"' WHERE ID='"+ ui->lineEdit_mgrID->text() +"' ");

   if(ui->lineEdit_mgrPlaque->text().length()>0)
            q.exec("UPDATE Managers set Plaque='"+ ui->lineEdit_mgrPlaque->text() +"' WHERE ID='"+ ui->lineEdit_mgrID->text() +"' ");


   q1.exec("UPDATE Managers set BDate='"+QString::number(d.year())+"-"+QString::number(d.month())+"-"+QString::number(d.day())+"' WHERE ID='"+ ui->lineEdit_mgrID->text() +"' ");





   query1.exec("SELECT * FROM Managers WHERE ID="+ui->lineEdit_mgrID->text()+"");


   if(query1.first()){

       QSqlQueryModel *n=new QSqlQueryModel ;
         n->setQuery(query1);
         ui ->tableView_mgr->setModel(n);

   }


}



void Update_manager::on_btn_save_updatemanager_2_clicked()
{
    close();
}

