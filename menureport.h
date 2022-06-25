#ifndef MENUREPORT_H
#define MENUREPORT_H

#include <QMainWindow>
#include"report_manager.h"
#include"report_customer.h"
#include"report_sale.h"
#include"sale.h"
#include"cancelbuy.h"
#include"update_car.h"
#include"report_base_price.h"
#include"report_compani.h"
#include"report_existingcar.h"

namespace Ui {
class MenuReport;
}

class MenuReport : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuReport(QWidget *parent = nullptr);
    ~MenuReport();

private slots:
    void on_commandLinkButton_manager_clicked();

    void on_commandLinkButton_customer_clicked();


    void on_commandLinkButton_sale_clicked();


    void on_pushButton_clicked();

    void on_commandLinkButton_company_clicked();

    void on_commandLinkButton_company_2_clicked();

    void on_commandLinkButton_company_3_clicked();

private:
    Ui::MenuReport *ui;
    Report_manager *report_manager;
    report_customer *Report_customer;
    Report_Sale *report_Sale;
    Report_ExistingCar *report_ExistingCar;
    Report_base_price *report_base_price;
    Report_compani *report_compani;



};

#endif // MENUREPORT_H
