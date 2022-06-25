#ifndef FINDIDCOMPANY_H
#define FINDIDCOMPANY_H

#include <QMainWindow>

namespace Ui {
class FindIDCompany;
}

class FindIDCompany : public QMainWindow
{
    Q_OBJECT

public:
    explicit FindIDCompany(QWidget *parent = nullptr);
    ~FindIDCompany();

private slots:
    void on_pushButton_inquiryCar_clicked();

    void on_pushButton_clicked();

private:
    Ui::FindIDCompany *ui;
};

#endif // FINDIDCOMPANY_H
