#include "report_existingcar.h"
#include "ui_report_existingcar.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPushButton>
#include <QMessageBox>

Report_ExistingCar::Report_ExistingCar(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Report_ExistingCar)
{
    ui->setupUi(this);



}

Report_ExistingCar::~Report_ExistingCar()
{
    delete ui;
}


void Report_ExistingCar::on_pushButton_clicked()
{
    ui->label_4->setText("Car Information");
    int num;
        QSqlQuery  query,query2;
        query.exec("SELECT * FROM Car Left Outer Join UsedCar ON Car.ID=UsedCar.UseID"
                   " WHERE Existing=1"
                   "ORDER BY CrDate ");
        if(!query.first())
            ui->label_4->setText("Not Exist!");
        QSqlQueryModel *m=new QSqlQueryModel;
        m->setQuery(query);
        ui->tableView->setModel(m);

        query2.exec("SELECT COUNT(*) FROM Car Left Outer Join UsedCar ON Car.ID=UsedCar.UseID"
                    " WHERE Existing=1");
        if(query2.first())
        {
           num= query2.value(0).toInt();
           ui->label_4->setText("Number of Cars available : "+QString::number(num)+"");
        }
}


void Report_ExistingCar::on_pushButton_close_clicked()
{
    QSqlQuery  q;
           // q.exec("SELECT * FROM Company WHERE CoName='"+ui->lineEdit->text()+"' ");
            QSqlQueryModel *m=new QSqlQueryModel;
            m->setQuery(q);
            ui->tableView->setModel(m);
            ui->label_4->setText("Car Information");
            Report_ExistingCar::close();
}

