#include "appdialog.h"
#include "ui_appdialog.h"

AppDialog::AppDialog(User* &user, QWidget *parent) :
    QDialog(parent),
    _user(user),
    ui(new Ui::AppDialog)
{
    ui->setupUi(this);

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

    string username = this->_user->getUsername();
    QString userQStr = QString::fromUtf8(username.c_str());

    user->getAccount()->setUsername(username);
    user->getAccount()->setMonth(ui->comboBox->currentIndex());

    ui->label_getUsername->setText(userQStr);
    user->getAccount()->writeData();

    user->getAccount()->setExpenseType("FOODBUDGET");
    double foodBudget = user->getAccount()->getExpense();
    ui->label_foodBudget->setText(QString::number(foodBudget));

    user->getAccount()->setExpenseType("RENTBUDGET");
    double rentBudget = user->getAccount()->getExpense();
    ui->label_rentBudget->setText(QString::number(rentBudget));

    user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
    double entertainmentBudget = user->getAccount()->getExpense();
    ui->label_entertainmentBudget->setText(QString::number(entertainmentBudget));

    user->getAccount()->setExpenseType("TUITIONBUDGET");
    double tuitionBudget = user->getAccount()->getExpense();
    ui->label_tuitionBudget->setText(QString::number(tuitionBudget));

    user->getAccount()->setExpenseType("SAVINGSBUDGET");
    double savingsBudget = user->getAccount()->getExpense();
    ui->label_savingsBudget->setText(QString::number(savingsBudget));

    user->getAccount()->setExpenseType("MISCBUDGET");
    double miscBudget = user->getAccount()->getExpense();
    ui->label_miscBudget->setText(QString::number(miscBudget));
}

AppDialog::~AppDialog()
{
    delete ui;
}

void AppDialog::on_pushButton_signOut_clicked()
{
    hide();
}
