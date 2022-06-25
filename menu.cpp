#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}



void menu::on_pushButton_insertMgr_clicked()
{
    insertManager =new InsertManager(this);
    insertManager->show();
}


void menu::on_pushButton_buyNew_clicked()
{
    Buy_NewCar =new buy_NewCar(this);
    Buy_NewCar->show();
}


void menu::on_pushButton_buyused_clicked()
{
    Buy_UsedCar =new buy_UsedCar(this);
    Buy_UsedCar->show();
}


void menu::on_pushButton_update_clicked()
{
    menuUpdate =new MenuUpdate(this);
    menuUpdate->show();
}


void menu::on_pushButton_report_clicked()
{
    menuReport =new MenuReport(this);
    menuReport->show();
}


void menu::on_pushButton_sale_clicked()
{
    menuSale =new MenuSale(this);
    menuSale->show();
}


void menu::on_pushButton_exit_clicked()
{
    menu::close();
}

