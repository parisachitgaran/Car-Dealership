#ifndef BUY_NEWCAR_H
#define BUY_NEWCAR_H

#include <QMainWindow>
#include "insertmanager.h"
#include "findidcompany.h"
#include "insertcompany.h"

QT_BEGIN_NAMESPACE
namespace Ui { class buy_NewCar; }
QT_END_NAMESPACE

class buy_NewCar : public QMainWindow
{
    Q_OBJECT

public:
    buy_NewCar(QWidget *parent = nullptr);
    ~buy_NewCar();


private slots:

    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_2_clicked();

    void on_refresh_clicked();

    void on_pushButton_3_clicked();

    void on_buy_new_clicked();

    void on_save_car_clicked();

private:
    Ui::buy_NewCar *ui;
    InsertManager *insertmanager=new InsertManager();
    FindIDCompany *findidcompany=new FindIDCompany();
    InsertCompany * insertcompany=new InsertCompany();
};
#endif // BUY_NEWCAR_H
