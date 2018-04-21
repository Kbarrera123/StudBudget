#include "makeaccountdialog.h"
#include "ui_makeaccountdialog.h"

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
