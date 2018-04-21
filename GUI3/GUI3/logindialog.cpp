#include "logindialog.h"
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
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

       if(username ==  "test" && password == "test") {
           //hide();
           appDialog = new AppDialog(this);
           appDialog->show();
           hide();
       }
       else {
           QMessageBox::warning(this,"Login", "Username or password is not correct");
       }
}
