#ifndef REPORT_BASE_PRICE_H
#define REPORT_BASE_PRICE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Report_base_price; }
QT_END_NAMESPACE

class Report_base_price : public QMainWindow
{
    Q_OBJECT

public:
    Report_base_price(QWidget *parent = nullptr);
    ~Report_base_price();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Report_base_price *ui;
};
#endif // REPORT_BASE_PRICE_H
