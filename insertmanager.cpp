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


InsertManager::InsertManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InsertManager)
{
    ui->setupUi(this);
    ui->plaque->setText("0");
    ui->home->setText("0");

}

InsertManager::~InsertManager()
{

    delete ui;
}

void InsertManager::on_pushButton_clicked()
{

    QSqlQuery  q;
   QDate d=ui->dateEdit->date();

   //Limitations
   bool check=false;
   bool flag=false;
   bool flag1=false;


    QString temp_phone= ui->home->text();
    QString temp_mobile= ui->mobile->text();
    QString temp_nid= ui->nid->text();
    QString temp_name= ui->name->text();
    QString temp_family= ui->family->text();
    QString temp_father= ui->fname->text();

    int tempPhone= temp_phone.length();
    int tempMobile= temp_mobile.length();
    int tempNid= temp_nid.length();
    int  tempName= temp_name.length();
    int tempFamily= temp_family.length();
    int tempFather= temp_father.length();
    int p=ui->plaque->text().toInt();

   if(ui->name->text()==""||ui->family->text()==""||ui->nid->text()==""||ui->mobile->text()=="")
   {
       flag1=true;
   }
   if(!(ui->radioButtonm->isChecked()) && !(ui->radioButtonw->isChecked()))
   {
       flag1=true;
   }
   if(flag1==true){
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

   for(int i=0;i<tempMobile;i++){
       if(!(temp_mobile[i]=='0'||temp_mobile[i]=='1'||temp_mobile[i]=='2'||temp_mobile[i]=='3'||temp_mobile[i]=='4'||temp_mobile[i]=='5'||temp_mobile[i]=='6'||temp_mobile[i]=='7'||temp_mobile[i]=='8'||temp_mobile[i]=='9')){
           if(check==false)
           {
           QMessageBox::information(this,"","The mobile number only contains the number!");
           check=true;
           }
       }
   }

   if(tempMobile!=11)
   {
       if(check==false)
       {
       QMessageBox::information(this,"","The mobile number contains 11 digits!");
       check=true;
       }
   }

   if(temp_mobile[0]!='0'){
       if(check==false)
       {
       QMessageBox::information(this,"","Mobile number must start with zero!");
       check=true;
       }
   }

   for(int i=0;i<tempNid;i++){
       if(!(temp_nid[i]=='0'||temp_nid[i]=='1'||temp_nid[i]=='2'||temp_nid[i]=='3'||temp_nid[i]=='4'||temp_nid[i]=='5'||temp_nid[i]=='6'||temp_nid[i]=='7'||temp_nid[i]=='8'||temp_nid[i]=='9')){
           if(check==false)
           {
           QMessageBox::information(this,"","The mobile National ID only contains the number!");
           check=true;
           }

       }
   }

   if(tempNid!=10)
   {
       if(check==false)
       {
        QMessageBox::information(this,"","The National ID contains 10 digits!");
       check=true;
       }
    }

   if(temp_nid[0]!='0')
   {
       if(check==false)
       {
       QMessageBox::information(this,"","National ID must start with zero!");
       check=true;
       }
    }

   if(p<0)
   {
       if(check==false)
       {
        QMessageBox::information(this,"","The plaque can not be negative!");
        check=true;
       }
   }


   for(int i=0;i<tempName;i++){
       if(!(temp_name[i]>='a' || temp_name[i]<="z" || temp_name[i]>="A" || temp_name[i]<="Z")){
           flag=true;

       }
   }

   for(int i=0;i<tempFamily;i++){
       if(!(temp_family[i]>='a' || temp_family[i]<="z" || temp_family[i]>="A" || temp_family[i]<="Z")){
           flag=true;

       }
   }

   for(int i=0;i<tempFather;i++){
       if(!(temp_father[i]>='a' || temp_father[i]<="z" || temp_father[i]>="A" || temp_father[i]<="Z" || temp_father[i]=="")){
           flag=true;

       }
   }

   if(flag==true)
  {
       if(check==false)
       {
          QMessageBox::information(this,"","The name contains only letters!");
          check=true;
       }
  }

   if(d.year()>2022){
    if(check==false)
    {
     QMessageBox::information(this,"","Date is not valid!");
     check=true;
    }
}

   if(check==false){
q.prepare("INSERT INTO Managers (Fname,Lname,Sex,FatherName,NationalID,BDate,Phone,Mobile,Street,Alley,Plaque) values ('"+ ui->name->text() +"','"+ui->family->text()+"',:Sex,'"+ui->fname->text()+"','"+ui->nid->text()+"','"+QString::number(d.year())+"-"+QString::number(d.month())+"-"+QString::number(d.day())+"',"+ ui->home->text() +",'"+ui->mobile->text()+"','"+ui->street->text() +"','"+ui->alley->text()+"',"+ui->plaque->text()+")");
if(ui->radioButtonm->isChecked())
    q.bindValue(":Sex",1);
if(ui->radioButtonw->isChecked())
    q.bindValue(":Sex",0);

if(!q.exec()){
    QMessageBox::information(this,"","Manager was not added successfully!");
}
else{

    QMessageBox::information(this,"","Manager was added successfully!");

    InsertManager::close();



}}}


void InsertManager::on_pushButton_2_clicked()
{
    close();
}

