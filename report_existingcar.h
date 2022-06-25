#ifndef REPORT_EXISTINGCAR_H
#define REPORT_EXISTINGCAR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Report_ExistingCar; }
QT_END_NAMESPACE

class Report_ExistingCar : public QMainWindow
{
    Q_OBJECT

public:
    Report_ExistingCar(QWidget *parent = nullptr);
    ~Report_ExistingCar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::Report_ExistingCar *ui;
};
#endif // REPORT_EXISTINGCAR_H
