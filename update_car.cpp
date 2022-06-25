#include "update_car.h"
#include "ui_update_car.h"

#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlError>
#include <QDebug>
#include<QMultiMap>
#include<QDate>
#include<QComboBox>


Update_car::Update_car(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Update_car)
{
    ui->setupUi(this);



    ui->lineEdit_bprice->setEnabled(false);
    ui->lineEdit_carname->setEnabled(false);
    ui->radioButton_no->setEnabled(false);
    ui->radioButton_yes->setEnabled(false);
    ui->lineEdit_cengine->setEnabled(false);
    ui->dateEdit_cdate->setEnabled(false);
    ui->lineEdit_color->setEnabled(false);
    ui->lineEdit_damage->setEnabled(false);
    ui->lineEdit_factory->setEnabled(false);
    ui->lineEdit_km->setEnabled(false);
    ui->lineEdit_model->setEnabled(false);
    ui->lineEdit_violation->setEnabled(false);

    ui->comboBox->setEnabled(false);


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

Update_car::~Update_car()
{
    delete ui;
}




void Update_car::on_pushButton_searchIDCar_clicked()
{
    QString carID=ui->lineEdit_carID->text();

    QSqlQuery query1,query2;
         query1.exec("SELECT ID FROM Car WHERE ID='"+carID+"' ");

         if(query1.first()){
              QMessageBox::information(this , " Car","This Car is Existing");

                   query2.exec("SELECT * FROM Car WHERE ID='"+carID+"' ");
                   QSqlQueryModel *n=new QSqlQueryModel;
                     n->setQuery(query2);
                     ui ->tableView_informationcar->setModel(n);

                     ui->comboBox->setEnabled(true);




                 }
          else{
                QMessageBox::information(this , "Car","This Car is not Existing");

               }

}


void Update_car::on_btn_save_updatecustomer_clicked()
{

    QSqlQuery q,q1,query1;

   QDate d=ui->dateEdit_cdate->date();


   if(ui->lineEdit_carname->text().length()>0)
            q.exec("UPDATE Car set Carname='"+ ui->lineEdit_carname->text() +"' WHERE ID='"+ ui->lineEdit_carID->text() +"' ");

   if(ui->lineEdit_cengine->text().length()>0)
            q.exec("UPDATE Car set EngineNum='"+ ui->lineEdit_cengine->text() +"' WHERE ID='"+ ui->lineEdit_carID->text() +"' ");

   if(ui->lineEdit_model->text().length()>0)
            q.exec("UPDATE Car set Model='"+ ui->lineEdit_model->text() +"' WHERE ID='"+ ui->lineEdit_carID->text() +"' ");


   if(ui->radioButton_yes->isChecked()){
            q.prepare("UPDATE Car set Existing=:Existing  WHERE ID='"+ ui->lineEdit_carID->text() +"' ");
            q.exec();
            q.bindValue(":Existing",1);
   }
   if(ui->radioButton_no->isChecked()){
            q.prepare("UPDATE Car set Existing=:Existing  WHERE ID='"+ ui->lineEdit_carID->text() +"' ");
            q.exec();
            q.bindValue(":Existing",0);
   }

   if(ui->lineEdit_color->text().length()>0)
            q.exec("UPDATE Car set Color='"+ ui->lineEdit_color->text() +"' WHERE ID='"+ ui->lineEdit_carID->text() +"' ");

   if(ui->lineEdit_factory->text().length()>0)
            q.exec("UPDATE Car set Factory='"+ ui->lineEdit_factory->text() +"' WHERE ID='"+ ui->lineEdit_carID->text() +"' ");

   if(ui->lineEdit_bprice->text().length()>0)
            q.exec("UPDATE Car set BuyPrice='"+ ui->lineEdit_bprice->text() +"' WHERE ID='"+ ui->lineEdit_carID->text() +"' ");


   if(ui->lineEdit_km->text().length()>0)
            q.exec("UPDATE UsedCar set KmUsed='"+ ui->lineEdit_km->text() +"' WHERE UseID='"+ ui->lineEdit_carID->text() +"' ");
   if(ui->lineEdit_violation->text().length()>0)
            q.exec("UPDATE UsedCar set Violations='"+ ui->lineEdit_violation->text() +"' WHERE UseID='"+ ui->lineEdit_carID->text() +"' ");
   if(ui->lineEdit_damage->text().length()>0)
            q.exec("UPDATE UsedCar set Damage='"+ ui->lineEdit_damage->text() +"' WHERE UseID='"+ ui->lineEdit_carID->text() +"' ");


    q1.exec("UPDATE Car set CrDate='"+QString::number(d.year())+"-"+QString::number(d.month())+"-"+QString::number(d.day())+"' WHERE ID='"+ ui->lineEdit_carID->text() +"' ");

    query1.exec("SELECT * FROM Car WHERE ID="+ui->lineEdit_carID->text()+"");


}


void Update_car::on_comboBox_currentTextChanged(const QString &arg1)
{
        QString usecar="Used Car";
        QSqlQuery query1,query2;
    if(ui->comboBox->currentText()==usecar){

        ui->lineEdit_bprice->setEnabled(true);
        ui->lineEdit_carname->setEnabled(true);
        ui->radioButton_no->setEnabled(true);
        ui->radioButton_yes->setEnabled(true);
        ui->lineEdit_cengine->setEnabled(true);
        ui->dateEdit_cdate->setEnabled(true);
        ui->lineEdit_color->setEnabled(true);
        ui->lineEdit_factory->setEnabled(true);
        ui->lineEdit_model->setEnabled(true);



            ui->lineEdit_damage->setEnabled(true);
            ui->lineEdit_km->setEnabled(true);
            ui->lineEdit_violation->setEnabled(true);
            query1.prepare("SELECT * FROM Car INNER JOIN UsedCar ON Car.ID=UsedCar.UseID");
            query1.exec();

            QSqlQueryModel *n=new QSqlQueryModel;
              n->setQuery(query1);
              ui ->tableView_informationcar->setModel(n);

    }
    else{
        ui->lineEdit_damage->setEnabled(false);
        ui->lineEdit_km->setEnabled(false);
        ui->lineEdit_violation->setEnabled(false);

        ui->lineEdit_bprice->setEnabled(true);
        ui->lineEdit_carname->setEnabled(true);
        ui->radioButton_no->setEnabled(true);
        ui->radioButton_yes->setEnabled(true);
        ui->lineEdit_cengine->setEnabled(true);
        ui->dateEdit_cdate->setEnabled(true);
        ui->lineEdit_color->setEnabled(true);
        ui->lineEdit_factory->setEnabled(true);
        ui->lineEdit_model->setEnabled(true);

        query2.exec("SELECT * FROM Car WHERE ID='"+ui->lineEdit_carID->text()+"' ");
        QSqlQueryModel *n=new QSqlQueryModel;
          n->setQuery(query2);
          ui ->tableView_informationcar->setModel(n);
    }
}


void Update_car::on_btn_save_updatecustomer_2_clicked()
{
    close();
}

