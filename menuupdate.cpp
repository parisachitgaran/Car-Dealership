#include "menuupdate.h"
#include "ui_menuupdate.h"

MenuUpdate::MenuUpdate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuUpdate)
{
    ui->setupUi(this);
}

MenuUpdate::~MenuUpdate()
{
    delete ui;
}

void MenuUpdate::on_LinkButton_manager_clicked()
{

    update_manager=new Update_manager(this);
    update_manager->show();

}


void MenuUpdate::on_LinkButton_customer_clicked()
{
    update_customer=new Update_customer(this);
    update_customer->show();

}



void MenuUpdate::on_LinkButton_Car_clicked()
{
    updatecar=new Update_car(this);
    updatecar->show();


}


void MenuUpdate::on_pushButton_clicked()
{
    MenuUpdate::close();
}

