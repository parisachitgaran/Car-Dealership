#ifndef UPDATE_CUSTOMER_H
#define UPDATE_CUSTOMER_H

#include <QMainWindow>

namespace Ui {
class Update_customer;
}

class Update_customer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Update_customer(QWidget *parent = nullptr);
    ~Update_customer();

private slots:
    void on_btn_save_updatecustomer_clicked();

    void on_searchIDcu_clicked();

    void on_btn_save_updatecustomer_2_clicked();

private:
    Ui::Update_customer *ui;
};

#endif // UPDATE_CUSTOMER_H
