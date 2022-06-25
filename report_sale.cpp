#include "report_sale.h"
#include "ui_report_sale.h"


#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlError>
#include <QDebug>
#include<QMultiMap>


Report_Sale::Report_Sale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Report_Sale)
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

Report_Sale::~Report_Sale()
{
    delete ui;
}

void Report_Sale::on_pushButton_show_clicked()
{
    QSqlQuery query1,query2;
    QDate dto,dfrom;
    QString Q;

    dto=ui->dateEdit_to->date();
    dfrom=ui->dateEdit_from->date();
    query1.prepare("SELECT * FROM Sale WHERE SDate "
                   "BETWEEN '"+QString::number(dfrom.year())+"-"+QString::number(dfrom.month())+"-"+QString::number(dfrom.day())+"' AND '"+QString::number(dto.year())+"-"+QString::number(dto.month())+"-"+QString::number(dto.day())+"' ");


    if(query1.exec()){

        QSqlQueryModel *n=new QSqlQueryModel ;
          n->setQuery(query1);
          ui ->tableView_ReSale->setModel(n);


    }

    else{
          QMessageBox::information(this , "Report","Report was not available");

        }

}


void Report_Sale::on_pushButton_close_clicked()
{
    close();
}

