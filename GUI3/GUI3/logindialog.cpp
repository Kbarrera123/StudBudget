#include "logindialog.h"
#include "authenticator.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LogInDialog::LogInDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInDialog)
{
    ui->setupUi(this);
}

LogInDialog::~LogInDialog()
{
    delete ui;
}

void LogInDialog::on_pushButton_Login_clicked()
{
    bool finished = false;
    Authenticator* authenticator = new Authenticator();
    authenticator->fillMapOfUsers();

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    std::string usernameStr = username.toUtf8().constData();
    std::string passwordStr = password.toUtf8().constData();

    authenticator->logIn(usernameStr, passwordStr, finished);
    User* user = authenticator->getUser();

       if(finished) {
           //hide();
           appDialog = new AppDialog(user, this);
           appDialog->show();
           hide();
       }
       else {
           QMessageBox::warning(this,"Login", "Username or password is not correct");
       }
}
