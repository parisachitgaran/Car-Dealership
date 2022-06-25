#ifndef ADD_MANAGER_H
#define ADD_MANAGER_H

#include <QMainWindow>

namespace Ui {
class Add_Manager;
}

class Add_Manager : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add_Manager(QWidget *parent = nullptr);
    ~Add_Manager();
    void on_pushButton_clicked();


private:
    Ui::Add_Manager *ui;
};

#endif // ADD_MANAGER_H
