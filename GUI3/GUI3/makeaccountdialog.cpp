#include "makeaccountdialog.h"
#include "ui_makeaccountdialog.h"
#include "authenticator.h"
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
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    Authenticator* authenticator = new Authenticator();

    std::string usernameStr = username.toUtf8().constData();
    std::string passwordStr = password.toUtf8().constData();

    authenticator->signUp(usernameStr, passwordStr);
    delete authenticator;

    logInDialog = new LogInDialog(this);
    logInDialog->show();
    hide();
}
