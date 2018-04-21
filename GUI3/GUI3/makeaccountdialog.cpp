#include "makeaccountdialog.h"
#include "ui_makeaccountdialog.h"
#include <QMessageBox>

MakeAccountDialog::MakeAccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MakeAccountDialog)
{
    ui->setupUi(this);
}

MakeAccountDialog::~MakeAccountDialog()
{
    delete ui;
}

void MakeAccountDialog::on_pushButton_accountMade_clicked()
{
    logInDialog = new LogInDialog(this);
    logInDialog->show();
    hide();
}
