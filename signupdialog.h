#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>

namespace Ui {
class signupDialog;
}

class signupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit signupDialog(QWidget *parent = 0);
    ~signupDialog();

private:
    Ui::signupDialog *ui;
};

#endif // SIGNUPDIALOG_H
