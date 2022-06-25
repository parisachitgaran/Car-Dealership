#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"menu.h"

#include <QWidget>
#include <QFont>
#include<QSqlDatabase>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_OK_clicked();



private:
    Ui::MainWindow *ui;
      menu * Menu;



};
#endif // MAINWINDOW_H