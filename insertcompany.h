#ifndef INSERTCOMPANY_H
#define INSERTCOMPANY_H

#include <QMainWindow>

namespace Ui {
class InsertCompany;
}

class InsertCompany : public QMainWindow
{
    Q_OBJECT

public:
    explicit InsertCompany(QWidget *parent = nullptr);
    ~InsertCompany();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InsertCompany *ui;
};

#endif // INSERTCOMPANY_H
