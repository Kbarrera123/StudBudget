#ifndef MAKEACCOUNTDIALOG_H
#define MAKEACCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class MakeAccountDialog;
}

class MakeAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MakeAccountDialog(QWidget *parent = 0);
    ~MakeAccountDialog();

private:
    Ui::MakeAccountDialog *ui;
};

#endif // MAKEACCOUNTDIALOG_H
