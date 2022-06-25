#ifndef BUY_USEDCAR_H
#define BUY_USEDCAR_H

#include <QMainWindow>
#include "insertmanager.h"
#include "insertcustomer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class buy_UsedCar; }
QT_END_NAMESPACE

class buy_UsedCar : public QMainWindow
{
    Q_OBJECT

public:
    buy_UsedCar(QWidget *parent = nullptr);
    ~buy_UsedCar();
    InsertManager *insertmanager=new InsertManager();
    InsertCustomer *insertcustomer=new InsertCustomer();

private slots:
    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

    void on_pushButton_refresh1_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_2_clicked();

    void on_save_car_clicked();

    void on_refresh_clicked();

    void on_buy_new_clicked();

private:
    Ui::buy_UsedCar *ui;
};
#endif // BUY_USEDCAR_H
