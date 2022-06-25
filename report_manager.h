#ifndef REPORT_MANAGER_H
#define REPORT_MANAGER_H

#include <QMainWindow>

namespace Ui {
class Report_manager;
}

class Report_manager : public QMainWindow
{
    Q_OBJECT

public:
    explicit Report_manager(QWidget *parent = nullptr);
    ~Report_manager();

private slots:

    void on_pushButton_show_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::Report_manager *ui;
};

#endif // REPORT_MANAGER_H
