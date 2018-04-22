#include "appdialog.h"
#include "ui_appdialog.h"
#include <QMessageBox>

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

    string username = user->getUsername();
    QString userQStr = QString::fromUtf8(username.c_str());

    user->getAccount()->setUsername(username);

    ui->label_getUsername->setText(userQStr);
    user->getAccount()->writeData();
    this->updateBalance();
    this->updateBudget();


}

AppDialog::~AppDialog()
{
    delete ui;
}

void AppDialog::on_pushButton_signOut_clicked()
{
    hide();
}

void AppDialog::setMonth(int month) {
    this->month = month;
}

void AppDialog::updateBudget(){
    this->_user->getAccount()->setMonth(this->month);

    this->_user->getAccount()->setExpenseType("FOODBUDGET");
    double foodBudget = this->_user->getAccount()->getExpense();
    ui->label_foodBudget->setText(QString::number(foodBudget));

    this->_user->getAccount()->setExpenseType("RENTBUDGET");
    double rentBudget = this->_user->getAccount()->getExpense();
    ui->label_rentBudget->setText(QString::number(rentBudget));

    this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
    double entertainmentBudget = this->_user->getAccount()->getExpense();
    ui->label_entertainmentBudget->setText(QString::number(entertainmentBudget));

    this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
    double tuitionBudget = this->_user->getAccount()->getExpense();
    ui->label_tuitionBudget->setText(QString::number(tuitionBudget));

    this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
    double savingsBudget = this->_user->getAccount()->getExpense();
    ui->label_savingsBudget->setText(QString::number(savingsBudget));

    this->_user->getAccount()->setExpenseType("MISCBUDGET");
    double miscBudget = this->_user->getAccount()->getExpense();
    ui->label_miscBudget->setText(QString::number(miscBudget));
}

void AppDialog::updateBalance(){
    this->_user->getAccount()->setMonth(this->month);

    this->_user->getAccount()->setExpenseType("FOOD");
    double foodCost = this->_user->getAccount()->getExpense();
    ui->label_foodCost->setText(QString::number(foodCost));

    this->_user->getAccount()->setExpenseType("RENT");
    double rentCost = this->_user->getAccount()->getExpense();
    ui->label_rentCost->setText(QString::number(rentCost));

    this->_user->getAccount()->setExpenseType("ENTERTAINMENT");
    double entertainmentCost = this->_user->getAccount()->getExpense();
    ui->label_entertainmentCost->setText(QString::number(entertainmentCost));

    this->_user->getAccount()->setExpenseType("TUITION");
    double tuitionCost = this->_user->getAccount()->getExpense();
    ui->label_tuitionCost->setText(QString::number(tuitionCost));

    this->_user->getAccount()->setExpenseType("SAVINGS");
    double savingsCost = this->_user->getAccount()->getExpense();
    ui->label_savingsCost->setText(QString::number(savingsCost));

    this->_user->getAccount()->setExpenseType("MISC");
    double miscCost = this->_user->getAccount()->getExpense();
    ui->label_miscCost->setText(QString::number(miscCost));
}

void AppDialog::on_comboBox_currentIndexChanged(int index)
{
    this->setMonth(index);
    this->_user->getAccount()->setMonth(this->month);
    this->_user->getAccount()->writeData();

    this->updateBudget();
    this->updateBalance();

}


void AppDialog::on_pushButton_depositFoodC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_foodCostChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("FOOD");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBalance();

}

void AppDialog::on_pushButton_withdrawFoodC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_foodCostChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("FOOD");
    this->_user->getAccount()->withdraw(withdrawAmtDouble);

    this->updateBalance();
}





void AppDialog::on_pushButton_depositRentC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_rentCostChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("RENT");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBalance();
}

void AppDialog::on_pushButton_withdrawRentC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_rentCostChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("RENT");
    this->_user->getAccount()->withdraw(withdrawAmtDouble);

    this->updateBalance();
}

void AppDialog::on_pushButton_depositEntertainmentC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_entertainmentCostChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("ENTERTAINMENT");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBalance();
}

void AppDialog::on_pushButton_withdrawEntertainmentC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_entertainmentCostChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("ENTERTAINMENT");
    this->_user->getAccount()->withdraw(withdrawAmtDouble);

    this->updateBalance();
}

void AppDialog::on_pushButton_depositTuitionC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_tuitionCostChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("TUITION");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBalance();
}

void AppDialog::on_pushButton_withdrawTuitionC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_tuitionCostChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("TUITION");
    this->_user->getAccount()->withdraw(withdrawAmtDouble);

    this->updateBalance();
}

void AppDialog::on_pushButton_depositSavingsC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_savingsCostChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("SAVINGS");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBalance();
}

void AppDialog::on_pushButton_withdrawSavingsC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_savingsCostChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("SAVINGS");
    this->_user->getAccount()->withdraw(withdrawAmtDouble);

    this->updateBalance();
}

void AppDialog::on_pushButton_depositMiscC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_miscCostChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("MISC");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBalance();
}

void AppDialog::on_pushButton_withdrawMiscC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_miscCostChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("MISC");
    this->_user->getAccount()->withdraw(withdrawAmtDouble);

    this->updateBalance();
}

void AppDialog::on_pushButton_depositFoodB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_foodBudgetChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("FOODBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
}
