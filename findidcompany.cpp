#include "findidcompany.h"
#include "ui_findidcompany.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPushButton>
#include <QDate>
#include<QMessageBox>


FindIDCompany::FindIDCompany(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FindIDCompany)
{
    ui->setupUi(this);

}

FindIDCompany::~FindIDCompany()
{
    delete ui;
}

void FindIDCompany::on_pushButton_inquiryCar_clicked()
{

    QSqlQuery  q;
    q.exec("SELECT * FROM Company WHERE CoName='"+ui->lineEdit->text()+"' ");
    if(!q.first())
        ui->label_5->setText("This company is not registered!");
    QSqlQueryModel *m=new QSqlQueryModel;
    m->setQuery(q);
    ui->tableView->setModel(m);
   }


void FindIDCompany::on_pushButton_clicked()
{
    QSqlQuery  q;
   // q.exec("SELECT * FROM Company WHERE CoName='"+ui->lineEdit->text()+"' ");
    QSqlQueryModel *m=new QSqlQueryModel;
    m->setQuery(q);
    ui->tableView->setModel(m);
    ui->lineEdit->setText("");

    FindIDCompany::close();
}

