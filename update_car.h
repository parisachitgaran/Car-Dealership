#ifndef UPDATE_CAR_H
#define UPDATE_CAR_H

#include <QMainWindow>

namespace Ui {
class Update_car;
}

class Update_car : public QMainWindow
{
    Q_OBJECT

public:
    explicit Update_car(QWidget *parent = nullptr);
    ~Update_car();

private slots:


    void on_pushButton_searchIDCar_clicked();

    void on_btn_save_updatecustomer_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_btn_save_updatecustomer_2_clicked();

private:
    Ui::Update_car *ui;
};

#endif // UPDATE_CAR_H
