#include "logindialog.h"
#include "ui_logindialog.h"

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

/*
void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

       if(username ==  "test" && password == "test") {
           QMessageBox::information(this, "Login", "Username and password is correct");
           //hide();
           appDialog = new AppDialog(this);
           appDialog->show();
       }
       else {
           QMessageBox::warning(this,"Login", "Username and password is not correct");
       }
}
*/
