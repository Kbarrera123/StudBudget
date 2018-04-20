#include "signupdialog.h"
#include "ui_signupdialog.h"

signupDialog::signupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupDialog)
{
    ui->setupUi(this);
}

signupDialog::~signupDialog()
{
    delete ui;
}
