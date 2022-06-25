#include "buy_newcar.h"
#include "ui_buy_newcar.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPushButton>
#include <QMessageBox>

buy_NewCar::buy_NewCar(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::buy_NewCar)
{
    ui->setupUi(this);



}

buy_NewCar::~buy_NewCar()
{
    delete ui;
}


void buy_NewCar::on_pushButton_clicked()
{
    ui->mgrid->clear();
   int  id;
   QString nid;
   nid=ui->lineEdit->text();
//connect to server
   QSqlQuery  q;
   q.exec("SELECT ID FROM  Managers WHERE NationalID= '"+nid+"'  ");

   if (q.first())
   {
    id= q.value(0).toInt();
       //qDebug()<<id;
    ui->label_ans->setText("Confirmed");
    QString mid= QString::number(id);
     ui->mgrid->setText(mid);
   }
   else {
       ui->label_ans->setText("This national code does not exist ");

   }
}







void buy_NewCar::on_commandLinkButton_clicked()
{


    insertmanager->show();

}


void buy_NewCar::on_pushButton_2_clicked()
{

    int  id;
 //connect to server
    QSqlQuery  q;
    q.exec("SELECT ID FROM Company WHERE ID= '"+ui->lineEdit_2->text()+"'  ");

    if (q.first())
    {
     id= q.value(0).toInt();
     ui->label_comp->setText("Confirmed");
     //ui->pushButton_2->setEnabled(true);
    }
    else {
        ui->label_comp->setText("This ID does not exist");

    }

}


void buy_NewCar::on_commandLinkButton_3_clicked()
{
    findidcompany->show();
}


void buy_NewCar::on_commandLinkButton_2_clicked()
{
    insertcompany->show();


}

void buy_NewCar::on_refresh_clicked()
{
        int i;
        QSqlQuery q2,q3;
        q2.exec("SELECT * FROM Company");
        if(q2.last())
         i= q2.value(0).toInt();

        QString idcompany=QString::number(i);
        ui->lineEdit_2->setText(idcompany);


}


void buy_NewCar::on_pushButton_3_clicked()
{

    int m;
    QSqlQuery q3;
    QString j;

    q3.exec("SELECT * FROM Managers");
    if(q3.last()){
      j= q3.value(5).toString();
      m=q3.value(0).toInt();
     }
   // QString idmanager=QString::number(j);
   ui->lineEdit->setText(j);

   QString mg=QString::number(m);
  ui->mgrid->setText(mg);

}


void buy_NewCar::on_buy_new_clicked()
{
 QSqlQuery query;
 QDate buydate;
 buydate=QDate :: currentDate();

 query.prepare("INSERT INTO CmpBuy (CarID,ComID,MgrID,BDate) VALUES("+ui->label_car->text()+","+ui->lineEdit_2->text()+","+ui->mgrid->text()+",'2020-02-02')");
 if(!query.exec()){
     QMessageBox::information(this,"","There is a problem with buying!");
 }
 else{

     QMessageBox::information(this,"","The Car was bought!");
     buy_NewCar::close();
 }

}




void buy_NewCar::on_save_car_clicked()
{
     ui->label_car->clear();

    QSqlQuery  q5,q6,q7;
   QDate creatdate=ui->dateEdit_crcar->date();

   //Limitations
   bool check=false;

    QString temp_engine= ui->lineEdit_engine->text();
    QString temp_price= ui->lineEdit_bprice->text();

    int tempEngine= temp_engine.length();
    int tempPrice= temp_price.length();

    int bprice=ui->lineEdit_bprice->text().toInt();


   if(ui->lineEdit_name->text()==""||ui->lineEdit_engine->text()==""||ui->lineEdit_model->text()==""||ui->lineEdit_factory->text()==""||ui->lineEdit_bprice->text()=="")
   {
       if(check==false)
       {
           check=true;
       QMessageBox::information(this,"","Fill in the required fields!");

       }
   }




   for(int i=0;i<tempEngine;i++){
       if(!(temp_engine[i]=='0'||temp_engine[i]=='1'||temp_engine[i]=='2'||temp_engine[i]=='3'||temp_engine[i]=='4'||temp_engine[i]=='5'||temp_engine[i]=='6'||temp_engine[i]=='7'||temp_engine[i]=='8'||temp_engine[i]=='9'||temp_engine[i]=="")){
           if(check==false)
           {
            QMessageBox::information(this,"","The Engine Number contains only the number!");
            check=true;
            }
       }
   }

   for(int i=0;i<tempPrice;i++){
       if(!(temp_price[i]=='0'||temp_price[i]=='1'||temp_price[i]=='2'||temp_price[i]=='3'||temp_price[i]=='4'||temp_price[i]=='5'||temp_price[i]=='6'||temp_price[i]=='7'||temp_price[i]=='8'||temp_price[i]=='9'||temp_price[i]=="")){
           if(check==false)
           {
            QMessageBox::information(this,"","Price contains only the number!");
            check=true;
            }
       }
   }


   if(bprice<0)
   {
       if(check==false)
       {
        QMessageBox::information(this,"","Buy Price can not be negative!");
        check=true;
       }
   }


   if(creatdate.year()>2022){
    if(check==false)
    {
     QMessageBox::information(this,"","Date is not valid!");
     check=true;
    }
}

   if(check==false){
  q5.prepare("INSERT INTO Car(Carname,EngineNum,Model,Color,Factory,CrDate,BuyPrice,Existing,CarType) values ('"+ ui->lineEdit_name->text() +"',"+ui->lineEdit_engine->text()+",'"+ui->lineEdit_model->text()+"','"+ ui->lineEdit_color->text() +"','"+ui->lineEdit_factory->text()+"','"+QString::number(creatdate.year())+"-"+QString::number(creatdate.month())+"-"+QString::number(creatdate.day())+"',"+ ui->lineEdit_bprice->text() +",1,'NewCar')");


if(q5.exec()){

    QMessageBox::information(this,"","NewCar was added successfully!");
    int idcar;
     q6.exec("SELECT * FROM Car");
     if(q6.last())
     {
         qDebug()<<q6.value(0)<<"car";
    idcar= q6.value(0).toInt();
     }
   QString ncar=QString::number(idcar);
    ui->label_car->setText(ncar);

    q7.exec("INSERT INTO NewCar(NID) VALUES ("+ui->label_car->text()+")");

    }
else{

    QMessageBox::information(this,"","NewCar was not added successfully!");
}

   }
}

