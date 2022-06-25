#include "insertcompany.h"
#include "ui_insertcompany.h"
#include "insertmanager.h"
#include "ui_insertmanager.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPushButton>
#include <QDate>
#include<QMessageBox>

InsertCompany::InsertCompany(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InsertCompany)
{
    ui->setupUi(this);

}

InsertCompany::~InsertCompany()
{
    delete ui;
}







void InsertCompany::on_pushButton_clicked()
{

    QSqlQuery  q;


   //Limitations
   bool check=false;


    QString temp_name= ui->name->text();
    QString temp_phone= ui->phone->text();

   int tempPhone=temp_phone.length();

    //int p=ui->plaque->text().toInt();

   if(ui->name->text()==""||ui->phone->text()=="")
   {
       if(check==false)
       {
           check=true;
       QMessageBox::information(this,"","Fill in the required fields!");

       }
   }


   for(int i=0;i<tempPhone;i++){
       if(!(temp_phone[i]=='0'||temp_phone[i]=='1'||temp_phone[i]=='2'||temp_phone[i]=='3'||temp_phone[i]=='4'||temp_phone[i]=='5'||temp_phone[i]=='6'||temp_phone[i]=='7'||temp_phone[i]=='8'||temp_phone[i]=='9'||temp_phone[i]=="")){
           if(check==false)
           {
            QMessageBox::information(this,"","The phone number contains only the number!");
            check=true;
            }
       }
   }


if(check==false){
q.prepare("INSERT INTO Company (CoName,Phone,Street,Alley,Plaque) Values ('"+ ui->name->text() +"',"+ui->phone->text()+",'"+ui->street->text() +"','"+ui->alley->text()+"',"+ui->plaque->text()+" )");
if(!q.exec()){
    QMessageBox::information(this,"","Company was not added successfully!");
}
else{

    QMessageBox::information(this,"","Company was added successfully!");

    //int idcomp;
    //QSqlQuery  q1;
   // q1.exec("SELECT ID FROM Company WHERE CoName='"+ui->name->text()+"' ");

   // idcomp=q1.value(0).toInt();

    //return idcomp;

    InsertCompany::close();

   }
   }
}

