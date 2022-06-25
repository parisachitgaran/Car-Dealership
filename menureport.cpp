#include "menureport.h"
#include "ui_menureport.h"

MenuReport::MenuReport(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuReport)
{
    ui->setupUi(this);
}

MenuReport::~MenuReport()
{
    delete ui;
}

void MenuReport::on_commandLinkButton_manager_clicked()
{
    report_manager=new Report_manager(this);
    report_manager->show();
}


void MenuReport::on_commandLinkButton_customer_clicked()
{
   Report_customer=new report_customer(this);
   Report_customer->show();
}


void MenuReport::on_commandLinkButton_sale_clicked()
{
    report_Sale=new Report_Sale(this);
    report_Sale->show();
}


void MenuReport::on_pushButton_clicked()
{
    MenuReport::close();
}


void MenuReport::on_commandLinkButton_company_clicked()
{
    report_compani=new Report_compani(this);
    report_compani->show();
}


void MenuReport::on_commandLinkButton_company_2_clicked()
{
    report_base_price=new Report_base_price(this);
    report_base_price->show();
}


void MenuReport::on_commandLinkButton_company_3_clicked()
{
    report_ExistingCar=new Report_ExistingCar(this);
    report_ExistingCar->show();
}

