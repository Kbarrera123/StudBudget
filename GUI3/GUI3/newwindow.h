#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QMainWindow>
#include "expenses.h"

namespace Ui {
class newWindow;
}

class newWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit newWindow(Expenses* &expenses, QWidget *parent = 0);
    ~newWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::newWindow *ui;
    Expenses* _expenses;
};

#endif // NEWWINDOW_H
