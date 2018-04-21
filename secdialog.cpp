#include "secdialog.h"
#include "ui_secdialog.h"

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    ui->comboBox->addItem("January");
    ui->comboBox->addItem("February");
    ui->comboBox->addItem("March");
    ui->comboBox->addItem("April");
    ui->comboBox->addItem("May");
    ui->comboBox->addItem("June");
    ui->comboBox->addItem("July");
    ui->comboBox->addItem("August");
    ui->comboBox->addItem("September");
    ui->comboBox->addItem("October");
    ui->comboBox->addItem("November");
    ui->comboBox->addItem("December");

    ui->comboBox_2->addItem("January");
    ui->comboBox_2->addItem("February");
    ui->comboBox_2->addItem("March");
    ui->comboBox_2->addItem("April");
    ui->comboBox_2->addItem("May");
    ui->comboBox_2->addItem("June");
    ui->comboBox_2->addItem("July");
    ui->comboBox_2->addItem("August");
    ui->comboBox_2->addItem("September");
    ui->comboBox_2->addItem("October");
    ui->comboBox_2->addItem("November");
    ui->comboBox_2->addItem("December");

}

SecDialog::~SecDialog()
{
    delete ui;
}


