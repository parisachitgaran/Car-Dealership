#include "add_manager.h"
#include "ui_add_manager.h"

Add_Manager::Add_Manager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Add_Manager)
{
    ui->setupUi(this);
}

Add_Manager::~Add_Manager()
{
    delete ui;
}
