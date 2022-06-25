#include "report_base_price.h"
#include "ui_report_base_price.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPushButton>
#include <QMessageBox>

Report_base_price::Report_base_price(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Report_base_price)
{
    ui->setupUi(this);



}

Report_base_price::~Report_base_price()
{
    delete ui;
}


void Report_base_price::on_pushButton_clicked()
{
     ui->label_4->setText("Car Information");
    QSqlQuery  query;
    query.exec("SELECT * FROM Car Left Outer Join UsedCar ON Car.ID=UsedCar.UseID"
               " WHERE BuyPrice BETWEEN "+ui->lineEdit->text()+" AND "+ui->lineEdit_2->text()+"   ");
    if(!query.first())
        ui->label_4->setText("Not Exist!");
    QSqlQueryModel *m=new QSqlQueryModel;
    m->setQuery(query);
    ui->tableView->setModel(m);
}


void Report_base_price::on_pushButton_2_clicked()
{
    QSqlQuery  q;
       // q.exec("SELECT * FROM Company WHERE CoName='"+ui->lineEdit->text()+"' ");
        QSqlQueryModel *m=new QSqlQueryModel;
        m->setQuery(q);
        ui->tableView->setModel(m);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->label_4->setText("Car Information");
        Report_base_price::close();
}

