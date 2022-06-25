#ifndef INSERTMANAGER_H
#define INSERTMANAGER_H

#include <QMainWindow>

namespace Ui {
class InsertManager;
}

class InsertManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit InsertManager(QWidget *parent = nullptr);
    ~InsertManager();
private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::InsertManager *ui;
};

#endif // INSERTMANAGER_H
