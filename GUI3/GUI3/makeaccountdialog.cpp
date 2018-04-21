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

    bool exists = false;

    std::string usernameStr = username.toUtf8().constData();
    std::string passwordStr = password.toUtf8().constData();

    authenticator->signUp(usernameStr, passwordStr, exists);
    delete authenticator;

    if (exists) {
        QMessageBox::warning(this, "Signup", "Username or password already in use! Try something else.");
    }

    logInDialog = new LogInDialog(this);
    logInDialog->show();
    hide();

}
