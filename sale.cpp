#include "sale.h"
#include "ui_sale.h"

#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlError>
#include <QDebug>
#include<QMultiMap>
#include<QDate>


Sale::Sale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sale)
{
    ui->setupUi(this);



    ui->lineEdit_cuFname->setEnabled(false);
    ui->lineEdit_cuLname->setEnabled(false);
    ui->radioButton_f->setEnabled(false);
    ui->radioButton_m->setEnabled(false);
    ui->lineEdit_cufathername->setEnabled(false);
    ui->dateEdit->setEnabled(false);
    ui->lineEdit_cuphone->setEnabled(false);
    ui->lineEdit_cunationalID->setEnabled(false);
    ui->lineEdit_cumobile->setEnabled(false);
    ui->lineEdit_custreet->setEnabled(false);
    ui->lineEdit_cualley->setEnabled(false);
    ui->lineEdit_cuplaque->setEnabled(false);

     ui->radioButton_paid->setEnabled(false);
      ui->radioButton_un->setEnabled(false);
      ui->lineEdit_paymethod->setEnabled(false);
       ui->lineEdit_salePrice->setEnabled(false);
        ui->dateEdit_deliver->setEnabled(false);

    ui->btn_save->setEnabled(false);
    ui->finish->setEnabled(false);


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

Sale::~Sale()
{
    delete ui;

}





////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////


// step1 : search car ID , if exist you can continue but if not you can't continue .
void Sale::on_pushButton_inquiryCar_clicked()
{



              QSqlQuery query1,query2;
                   query1.exec("SELECT ID FROM Car"
                               " WHERE ID="+ui->lineEdit_carID->text()+" AND Existing=1 ");


                   if(query1.first()){
                        QMessageBox::information(this , "inquiryCar","This car is available or Existing");

                           query2.prepare("SELECT * FROM Car WHERE ID="+ui->lineEdit_carID->text()+" ");

                            query2.exec();
                             QSqlQueryModel *n=new QSqlQueryModel ;
                               n->setQuery(query2);

                               ui ->tableView->setModel(n);

                               ui->btn_save->setEnabled(true);

                   }

                   else{
                       QMessageBox::information(this , "inquiryCar","This car is not available or not Existing");

                    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////

// step2 : search customer ID , if exist you see this customer in table ,
//but if not exist you must enter informatoin for new costomer
void Sale::on_searchID_clicked()
{

             QString customerID=ui->lineEdit_cuID->text();


              QSqlQuery query1,query2;
                   query1.exec("SELECT ID FROM Customer WHERE ID='"+customerID+"' ");

                   if(query1.first()){
                             QMessageBox::information(this , "Customer","This Customer is Existing");

                             query2.exec("SELECT * FROM Customer WHERE ID='"+customerID+"' ");

                             QSqlQueryModel *n=new QSqlQueryModel;
                             n->setQuery(query2);
                               ui ->tableView_Customer->setModel(n);
                            //   ui->Next->setEnabled(true);

                   }
                   else{
                       QMessageBox::information(this , "Customer","This Customer is not Existing/n Please fill the 'Customer information' form");
                       ui->lineEdit_cuFname->setEnabled(true);
                       ui->lineEdit_cuLname->setEnabled(true);
                       ui->radioButton_f->setEnabled(true);
                       ui->radioButton_m->setEnabled(true);
                       ui->lineEdit_cufathername->setEnabled(true);
                       ui->dateEdit->setEnabled(true);
                       ui->lineEdit_cuphone->setEnabled(true);
                       ui->lineEdit_cunationalID->setEnabled(true);
                       ui->lineEdit_cumobile->setEnabled(true);
                       ui->lineEdit_custreet->setEnabled(true);
                       ui->lineEdit_cualley->setEnabled(true);
                       ui->lineEdit_cuplaque->setEnabled(true);


                   }

}


////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////

//new customer save to Databse
void Sale::on_btn_save_clicked()
{

    QSqlQuery q;

   QDate da=ui->dateEdit->date();



    QDate d=ui->dateEdit->date();

       //Limitations
       bool check=false;
       bool flag=false;
       bool flag1=false;


        QString temp_phone= ui->lineEdit_cuphone->text();
        QString temp_mobile= ui->lineEdit_cumobile->text();
        QString temp_nid= ui->lineEdit_cunationalID->text();
        QString temp_name= ui->lineEdit_cuFname->text();
        QString temp_family= ui->lineEdit_cuLname->text();
        QString temp_father= ui->lineEdit_cufathername->text();

        int tempPhone= temp_phone.length();
        int tempMobile= temp_mobile.length();
        int tempNid= temp_nid.length();
        int  tempName= temp_name.length();
        int tempFamily= temp_family.length();
        int tempFather= temp_father.length();
        int p=ui->lineEdit_cuplaque->text().toInt();

       if(ui->lineEdit_cuFname->text()==""||ui->lineEdit_cuLname->text()==""||ui->lineEdit_cunationalID->text()==""||ui->lineEdit_cumobile->text()=="")
       {
           flag1=true;
       }
       if(!(ui->radioButton_m->isChecked()) && !(ui->radioButton_f->isChecked()))
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
       q.prepare("INSERT INTO Customer (Fname,Lname,Sex,FatherName,NationalID,BDate,Phone,Mobile,Street,Alley,Plaque)"
                 " values ('"+ ui->lineEdit_cuFname->text() +"','"+ui->lineEdit_cuLname->text()+"',:Sex,'"+ui->lineEdit_cufathername->text()+"','"+ui->lineEdit_cunationalID->text()+"','"+QString::number(da.year())+"-"+QString::number(da.month())+"-"+QString::number(da.day())+"',"+ ui->lineEdit_cuphone->text() +",'"+ui->lineEdit_cumobile->text()+"','"+ui->lineEdit_custreet->text() +"','"+ui->lineEdit_cualley->text()+"',"+ui->lineEdit_cuplaque->text()+")");

       if(ui->radioButton_m->isChecked()){
           q.bindValue(":Sex",1);
       }

       if(ui->radioButton_f->isChecked()){
       q.bindValue(":Sex",0);
       }
    if(!q.exec()){
                     qDebug() << q.lastError().text() << q.lastQuery();
                     QMessageBox::information(this , "Customer","Customer was not added successfully.");


                 }
          else{
                       qDebug() << "else "<< q.lastQuery();
                       QMessageBox::information(this , "Customer","Customer was added successfully.");



             }
}


}


////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////

//   step3 : search manager ID , if exist you can continue but if not you can't continue .

void Sale::on_searchIDmgr_clicked()
{
    QString MgrID=ui->lineEdit_mgrID->text();


     QSqlQuery query1;
          query1.exec("SELECT ID FROM Managers WHERE ID='"+MgrID+"' ");

          if(query1.first()){
                    QMessageBox::information(this , "Manager","This Manager is Existing");


                    ui->radioButton_paid->setEnabled(true);
                      ui->radioButton_un->setEnabled(true);
                     ui->lineEdit_paymethod->setEnabled(true);
                      ui->lineEdit_salePrice->setEnabled(true);
                       ui->dateEdit_deliver->setEnabled(true);


                      ui->finish->setEnabled(true);

          }
          else{
              QMessageBox::information(this , "Customer","This Manager is not Existing");

          }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////

//   final : after fill all form , you click this butten and new Sale insert to Database
// and "Existing" Car become 0 .
void Sale::on_finish_clicked()
{

    QSqlQuery q3,q4;

    QDate dS;
    dS=QDate :: currentDate();

    QDate dD=ui->dateEdit_deliver->date();

    // Limited
    bool check=false, flag1=false;


    //BEGIN LIMITED FOR NOTNULL FIELD//////////////////////////
    if(ui->lineEdit_paymethod->text()=="")
       {
           flag1=true;
       }
       if(!(ui->radioButton_paid->isChecked()) && !(ui->radioButton_un->isChecked()))
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
      //END LIMITED FOR NOTNULL FIELD//////////////////////////


       //BEGIN LIMITE FOR Sale PRICE///////////////////////////////////////////

           QString temp_price= ui->lineEdit_salePrice->text();


           int tempPrice= temp_price.length();

           int bprice=ui->lineEdit_salePrice->text().toInt();


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

       //END LIMITE FOR Sale PRICE///////////////////////////////////////////////

       //BEGIN LIMITE FOR Delivery Date///////////////////////////////////////////////

           QDate date =ui->dateEdit_deliver->date();
               if(date.year()>2022){
                if(check==false)
                {
                 QMessageBox::information(this,"","Date is not valid!");
                 check=true;
                }
            }

       //BEGIN LIMITE FOR ANY DATE///////////////////////////////////////////////





    // end Limited



    q3.prepare("INSERT INTO Sale(CarID,CustID,MgrID,SalePrice,SDate,DlverDate,PaymentMethod,Payment)"
             " values('"+ui->lineEdit_carID->text()+"','"+ui->lineEdit_cuID->text()+"','"+ui->lineEdit_mgrID->text()+"','"+ui->lineEdit_salePrice->text()+"','"+QString::number(dS.year())+"-"+QString::number(dS.month())+"-"+QString::number(dS.day())+"','"+QString::number(dD.year())+"-"+QString::number(dD.month())+"-"+QString::number(dD.day())+"','"+ui->lineEdit_paymethod->text()+"',:Payment)");
    if(ui->radioButton_paid->isChecked()){
        q3.bindValue(":Payment",1);
    }

    if(ui->radioButton_un->isChecked()){
       q3.bindValue(":Payment",0);
    }

    if(!q3.exec()){
                     qDebug() << q3.lastError().text() << q3.lastQuery();
                     QMessageBox::information(this , "Sale","Sale was not successfully.");


                 }
          else{
                     q4.prepare("UPDATE Car set Existing=0 WHERE ID='"+ ui->lineEdit_carID->text() +"' ");
                     q4.exec();
                   //  q4.bindValue(":Existing",0);
                     qDebug() << "else "<< q3.lastQuery();

                       QMessageBox::information(this , "Sale","Sale was successfully.");

             }

}

void Sale::on_commandLinkButton_addMgr_clicked()
{
    insertManager =new InsertManager(this);
    insertManager->show();
}

