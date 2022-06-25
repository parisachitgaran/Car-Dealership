#ifndef MENU_H
#define MENU_H

#include"insertmanager.h"
#include"buy_usedcar.h"
#include"buy_newcar.h"
#include"menusale.h"
#include"menureport.h"
#include"menuupdate.h"

#include <QMainWindow>

namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:


    void on_pushButton_insertMgr_clicked();

    void on_pushButton_buyNew_clicked();

    void on_pushButton_buyused_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_report_clicked();

    void on_pushButton_sale_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::menu *ui;
    InsertManager *insertManager;
    buy_UsedCar *Buy_UsedCar;
    buy_NewCar *Buy_NewCar;
    MenuReport *menuReport;
    MenuSale *menuSale;
    MenuUpdate *menuUpdate;


};

#endif // MENU_H
