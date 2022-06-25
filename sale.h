#ifndef SALE_H
#define SALE_H

#include <QMainWindow>
#include"insertmanager.h"


namespace Ui {
class Sale;
}

class Sale : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sale(QWidget *parent = nullptr);
    ~Sale();


private slots:
    void on_pushButton_inquiryCar_clicked();

    void on_searchID_clicked();

   // void on_pushButton_clicked();

    void on_btn_save_clicked();

    void on_searchIDmgr_clicked();

    void on_finish_clicked();

    void on_commandLinkButton_addMgr_clicked();

private:
    Ui::Sale *ui;
    InsertManager *insertManager;
};

#endif // SALE_H
