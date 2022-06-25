#include "car.h"
#include "ui_car.h"

Car::Car(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Car)
{
    ui->setupUi(this);
}

Car::~Car()
{
    delete ui;
}
