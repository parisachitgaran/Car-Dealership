#ifndef REPORT_SALE_H
#define REPORT_SALE_H

#include <QMainWindow>

namespace Ui {
class Report_Sale;
}

class Report_Sale : public QMainWindow
{
    Q_OBJECT

public:
    explicit Report_Sale(QWidget *parent = nullptr);
    ~Report_Sale();

private slots:
    void on_pushButton_show_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::Report_Sale *ui;
};

#endif // REPORT_SALE_H
