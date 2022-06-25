#include "menusale.h"
#include "ui_menusale.h"

MenuSale::MenuSale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuSale)
{
    ui->setupUi(this);
}

MenuSale::~MenuSale()
{
    delete ui;
}



/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void MenuSale::on_commandLinkButton_clicked()
{

    sale = new Sale(this);
    sale ->show();


}


/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
///
///
void MenuSale::on_commandLinkButton_2_clicked()
{
    cancelbuy = new Cancelbuy(this);
    cancelbuy ->show();
}




void MenuSale::on_pushButton_clicked()
{
    MenuSale ::close();
}

