#ifndef REPORT_CUSTOMER_H
#define REPORT_CUSTOMER_H

#include <QMainWindow>

namespace Ui {
class report_customer;
}

class report_customer : public QMainWindow
{
    Q_OBJECT

public:
    explicit report_customer(QWidget *parent = nullptr);
    ~report_customer();

private slots:
    void on_pushButton_show_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::report_customer *ui;
};

#endif // REPORT_CUSTOMER_H
