#ifndef MENUSALE_H
#define MENUSALE_H

#include<sale.h>
#include<cancelbuy.h>
#include <QMainWindow>


namespace Ui {
class MenuSale;
}

class MenuSale : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuSale(QWidget *parent = nullptr);
    ~MenuSale();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();



    void on_pushButton_clicked();

private:
    Ui::MenuSale *ui;

      Sale *sale;
      Cancelbuy * cancelbuy;

};

#endif // MENUSALE_H
