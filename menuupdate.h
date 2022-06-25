#ifndef MENUUPDATE_H
#define MENUUPDATE_H

#include <QMainWindow>
#include"update_customer.h"
#include"update_manager.h"
#include"update_car.h"

namespace Ui {
class MenuUpdate;
}

class MenuUpdate : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuUpdate(QWidget *parent = nullptr);
    ~MenuUpdate();

private slots:
    void on_LinkButton_manager_clicked();

    void on_LinkButton_customer_clicked();

  //  void on_LinkButton_Car_clicked();

    void on_LinkButton_Car_clicked();

    void on_pushButton_clicked();

private:
    Ui::MenuUpdate *ui;

    Update_customer *update_customer;
    Update_manager *update_manager;
    Update_car *updatecar;


};

#endif // MENUUPDATE_H
