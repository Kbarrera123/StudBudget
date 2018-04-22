#ifndef APPDIALOG_H
#define APPDIALOG_H

#include <QDialog>
#include "user.h"

namespace Ui {
class AppDialog;
}

class AppDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AppDialog(User* &user, QWidget *parent = 0);
    ~AppDialog();

private slots:
    void on_pushButton_signOut_clicked();

private:
    User* _user;
    Ui::AppDialog *ui;
};

#endif // APPDIALOG_H
