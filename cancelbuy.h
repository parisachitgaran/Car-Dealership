#ifndef CANCELBUY_H
#define CANCELBUY_H

#include <QMainWindow>



namespace Ui {
class Cancelbuy;
}

class Cancelbuy : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cancelbuy(QWidget *parent = nullptr);
    ~Cancelbuy();

private slots:

    void on_pushButton_Save_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::Cancelbuy *ui;
};

#endif // CANCELBUY_H
