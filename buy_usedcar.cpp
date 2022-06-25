#include "buy_usedcar.h"
#include "ui_buy_usedcar.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPushButton>
#include <QMessageBox>


buy_UsedCar::buy_UsedCar(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::buy_UsedCar)
{
    ui->setupUi(this);


}

buy_UsedCar::~buy_UsedCar()
{
    delete ui;


}

//Manager

void buy_UsedCar::on_pushButton_clicked()
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
     QString manageid=QString::number(id);
      ui->mgrid->setText(manageid);
    }
    else {
        ui->label_ans->setText("This national code does not exist ");

    }
}


void buy_UsedCar::on_commandLinkButton_clicked()
{
insertmanager->show();
}


void buy_UsedCar::on_pushButton_refresh1_clicked()
{

    int h;
    QSqlQuery q3;
    QString j;
    q3.exec("SELECT * FROM Managers");
    if(q3.last())
    {
      j= q3.value(5).toString();
      h= q3.value(0).toInt();
     }
    //QString idmanager=QString::number(j);
   ui->lineEdit->setText(j);


   QString mngid=QString::number(h);
    ui->mgrid->setText(mngid);
}





//Customer

void buy_UsedCar::on_pushButton_2_clicked()
{
    ui->custid->clear();
    int  id;
   // QString nidcustomer;
   // nidcustomer=ui->lineEdit_2->text();
 //connect to server
    QSqlQuery  q;
    q.exec("SELECT ID FROM  Customer WHERE NationalID= '"+ui->lineEdit_2->text()+"'  ");

    if (q.first())
    {
     id= q.value(0).toInt();
     ui->label_ans2->setText("Confirmed");
     QString customerid=QString::number(id);
      ui->custid->setText(customerid);
    }
    else {
        ui->label_ans2->setText("This National Code does not exist ");
    }

}


void buy_UsedCar::on_commandLinkButton_2_clicked()
{
    insertcustomer->show();
}

void buy_UsedCar::on_refresh_clicked()
{
    int t;
    QSqlQuery q;
    QString f;

    q.exec("SELECT * FROM Customer");
    if(q.last())
    {
      f= q.value(5).toString();
      t= q.value(0).toInt();
     }
    //QString idc=QString::number(f);
   ui->lineEdit_2->setText(f);


   QString c=QString::number(t);
    ui->custid->setText(c);
}

//Car

void buy_UsedCar::on_save_car_clicked()
{
    ui->label_car->clear();

    QSqlQuery  q5,q6,q7;
   QDate creatdate=ui->dateEdit_crcar->date();

   //Limitations
   bool check=false;

    QString temp_engine= ui->lineEdit_engine->text();
    QString temp_damage= ui->lineEdit_damage->text();
    QString temp_price= ui->lineEdit_bprice->text();

    int tempEngine= temp_engine.length();
    int tempDamage= temp_damage.length();
    int tempPrice= temp_price.length();

    int bprice=ui->lineEdit_bprice->text().toInt();
    int damage=ui->lineEdit_damage->text().toInt();

   if(ui->lineEdit_name->text()==""||ui->lineEdit_engine->text()==""||ui->lineEdit_model->text()==""||ui->lineEdit_factory->text()==""||ui->lineEdit_bprice->text()==""||ui->lineEdit_damage->text()==""||ui->lineEdit_km->text()=="")
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

   for(int i=0;i<tempDamage;i++){
       if(!(temp_damage[i]=='0'||temp_damage[i]=='1'||temp_damage[i]=='2'||temp_damage[i]=='3'||temp_damage[i]=='4'||temp_damage[i]=='5'||temp_damage[i]=='6'||temp_damage[i]=='7'||temp_damage[i]=='8'||temp_damage[i]=='9'||temp_damage[i]=="")){
           if(check==false)
           {
            QMessageBox::information(this,"","The Damage should only contain a number!");
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

   if(damage<0 || damage>100)
   {
       if(check==false)
       {
        QMessageBox::information(this,"","Invalid Damage value!");
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
  q5.prepare("INSERT INTO Car(Carname,EngineNum,Model,Color,Factory,CrDate,BuyPrice,Existing,CarType) values ('"+ ui->lineEdit_name->text() +"',"+ui->lineEdit_engine->text()+",'"+ui->lineEdit_model->text()+"','"+ ui->lineEdit_color->text() +"','"+ui->lineEdit_factory->text()+"','"+QString::number(creatdate.year())+"-"+QString::number(creatdate.month())+"-"+QString::number(creatdate.day())+"',"+ ui->lineEdit_bprice->text() +",1,'UsedCar')");


if(q5.exec()){

    QMessageBox::information(this,"","The UsedCar was added successfully!");
    int idcar;
     q6.exec("SELECT * FROM Car");
     if(q6.last())
     {
         //qDebug()<<q6.value(0)<<"car";
    idcar= q6.value(0).toInt();
     }
   QString ncar=QString::number(idcar);
    ui->label_car->setText(ncar);

    q7.exec("INSERT INTO UsedCar(UseID,Violations,Damage,KmUsed) VALUES ("+ui->label_car->text()+",'"+ui->lineEdit_violation->text()+"',"+ui->lineEdit_damage->text()+","+ui->lineEdit_km->text()+")");

    }
else
{
QMessageBox::information(this,"","The UsedCar was not added successfully!");
}


   }
}


void buy_UsedCar::on_buy_new_clicked()
{
    QSqlQuery query,query0;

    QDate buydate;
    buydate=QDate :: currentDate();

    query.prepare("INSERT INTO CustBuy (CarID,CustID,MgrID,BDate) VALUES("+ui->label_car->text()+","+ui->custid->text()+","+ui->mgrid->text()+",'"+QString::number(buydate.year())+"-"+QString::number(buydate.month())+"-"+QString::number(buydate.day())+"')");
    if(!query.exec()){
        QMessageBox::information(this,"","There is a problem with buying!");
    }
    else{

        QMessageBox::information(this,"","The Car was bought!");
        buy_UsedCar::close();
    }
}

