#ifndef REPORT_COMPANI_H
#define REPORT_COMPANI_H

#include <QMainWindow>

namespace Ui {
class Report_compani;
}

class Report_compani : public QMainWindow
{
    Q_OBJECT

public:
    explicit Report_compani(QWidget *parent = nullptr);
    ~Report_compani();

private slots:
    void on_pushButton_show_clicked();

private:
    Ui::Report_compani *ui;
};

#endif // REPORT_COMPANI_H
