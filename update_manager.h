#ifndef UPDATE_MANAGER_H
#define UPDATE_MANAGER_H

#include <QMainWindow>

namespace Ui {
class Update_manager;
}

class Update_manager : public QMainWindow
{
    Q_OBJECT

public:
    explicit Update_manager(QWidget *parent = nullptr);
    ~Update_manager();

private slots:

    void on_btn_save_updatemanager_clicked();

    void on_searchIDmgr_clicked();

    void on_btn_save_updatemanager_2_clicked();

private:
    Ui::Update_manager *ui;
};

#endif // UPDATE_MANAGER_H
