#include "report_customer.h"
#include "ui_report_customer.h"

#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QSqlError>
#include <QDebug>
#include<QMultiMap>

report_customer::report_customer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::report_customer)
{
    ui->setupUi(this);


    // connect Database
   ////////////////////////////////////////////////////////////////////////

}

report_customer::~report_customer()
{
    delete ui;
}

void report_customer::on_pushButton_show_clicked()
{
    QSqlQuery query1;
    QString Q;


    query1.prepare("SELECT * FROM Customer ORDER BY Lname ASC");


    if(query1.exec()){

        QSqlQueryModel *n=new QSqlQueryModel ;
          n->setQuery(query1);
          ui ->tableView_ReCu->setModel(n);

    }

    else{
        QMessageBox::information(this , "Report","Report was not available");

     }

}


void report_customer::on_pushButton_close_clicked()
{
    close();
}

