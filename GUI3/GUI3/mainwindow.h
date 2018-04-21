#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appdialog.h"
#include "logindialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_signUp_clicked();

private:
    Ui::MainWindow *ui;
    AppDialog *appDialog;
    LogInDialog *loginDialog;
};

#endif // MAINWINDOW_H
