#ifndef INSERTCUSTOMER_H
#define INSERTCUSTOMER_H

#include <QMainWindow>

namespace Ui {
class InsertCustomer;
}

class InsertCustomer : public QMainWindow
{
    Q_OBJECT

public:
    explicit InsertCustomer(QWidget *parent = nullptr);
    ~InsertCustomer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InsertCustomer *ui;
};

#endif // INSERTCUSTOMER_H
