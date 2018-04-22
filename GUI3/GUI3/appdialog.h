#ifndef APPDIALOG_H
#define APPDIALOG_H

#include <QDialog>
#include "user.h"
#include "account.h"

namespace Ui {
class AppDialog;
}

class AppDialog : public QDialog
{
    Q_OBJECT

public:
    void setMonth(int month);
    void updateBudget();
    void updateBalance();
    explicit AppDialog(User* &user, QWidget *parent = 0);
    ~AppDialog();

private slots:
    void on_pushButton_signOut_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_depositFoodC_clicked();

private:
    User* _user;
    int month;
    Ui::AppDialog *ui;
};

#endif // APPDIALOG_H
