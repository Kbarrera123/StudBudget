#ifndef APPDIALOG_H
#define APPDIALOG_H

#include <QDialog>

namespace Ui {
class AppDialog;
}

class AppDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AppDialog(QWidget *parent = 0);
    ~AppDialog();

private slots:
    void on_pushButton_signOut_clicked();

private:
    Ui::AppDialog *ui;
};

#endif // APPDIALOG_H
