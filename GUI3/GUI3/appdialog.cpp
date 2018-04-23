#include "appdialog.h"
#include "ui_appdialog.h"
#include <QMessageBox>

AppDialog::AppDialog(User* &user, QWidget *parent) :
    QDialog(parent),
    _user(user),
    ui(new Ui::AppDialog)
{
    ui->setupUi(this);

    ui->comboBox_monthBalance->addItem("January");
    ui->comboBox_monthBalance->addItem("February");
    ui->comboBox_monthBalance->addItem("March");
    ui->comboBox_monthBalance->addItem("April");
    ui->comboBox_monthBalance->addItem("May");
    ui->comboBox_monthBalance->addItem("June");
    ui->comboBox_monthBalance->addItem("July");
    ui->comboBox_monthBalance->addItem("August");
    ui->comboBox_monthBalance->addItem("September");
    ui->comboBox_monthBalance->addItem("October");
    ui->comboBox_monthBalance->addItem("November");
    ui->comboBox_monthBalance->addItem("December");

    ui->comboBox_monthBudget->addItem("January");
    ui->comboBox_monthBudget->addItem("February");
    ui->comboBox_monthBudget->addItem("March");
    ui->comboBox_monthBudget->addItem("April");
    ui->comboBox_monthBudget->addItem("May");
    ui->comboBox_monthBudget->addItem("June");
    ui->comboBox_monthBudget->addItem("July");
    ui->comboBox_monthBudget->addItem("August");
    ui->comboBox_monthBudget->addItem("September");
    ui->comboBox_monthBudget->addItem("October");
    ui->comboBox_monthBudget->addItem("November");
    ui->comboBox_monthBudget->addItem("December");

    ui->tabWidget->setCurrentIndex(0);

    string username = user->getUsername();
    QString userQStr = QString::fromUtf8((username + '!').c_str());
    ui->label_getUsername->setText(userQStr);

    user->getAccount()->setUsername(username);
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
    ui->label_foodBudget->repaint();

    this->_user->getAccount()->setExpenseType("RENTBUDGET");
    double rentBudget = this->_user->getAccount()->getExpense();
    ui->label_rentBudget->setText(QString::number(rentBudget));
    ui->label_rentBudget->repaint();

    this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
    double entertainmentBudget = this->_user->getAccount()->getExpense();
    ui->label_entertainmentBudget->setText(QString::number(entertainmentBudget));
    ui->label_entertainmentBudget->repaint();

    this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
    double tuitionBudget = this->_user->getAccount()->getExpense();
    ui->label_tuitionBudget->setText(QString::number(tuitionBudget));
    ui->label_tuitionBudget->repaint();

    this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
    double savingsBudget = this->_user->getAccount()->getExpense();
    ui->label_savingsBudget->setText(QString::number(savingsBudget));
    ui->label_savingsBudget->repaint();

    this->_user->getAccount()->setExpenseType("MISCBUDGET");
    double miscBudget = this->_user->getAccount()->getExpense();
    ui->label_miscBudget->setText(QString::number(miscBudget));
    ui->label_miscBudget->repaint();

    //this->_user->getAccount()->fillArrayExpenses();

    std::string finAdvice = this->_user->getAccount()->getFinancialAdvice(this->month);
    QString finAdviceQStr = QString::fromUtf8(finAdvice.c_str());

    ui->label_financialAdvice->setText(finAdviceQStr);
    ui->label_financialAdvice->repaint();
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

    //this->_user->getAccount()->fillArrayExpenses();

    std::string finAdvice = this->_user->getAccount()->getFinancialAdvice(this->month);
    QString finAdviceQStr = QString::fromUtf8(finAdvice.c_str());


    ui->label_financialAdvice->setText(finAdviceQStr);
    ui->label_financialAdvice->repaint();
}

void AppDialog::on_comboBox_monthBalance_currentIndexChanged(int index)
{
    this->setMonth(index);
    this->_user->getAccount()->setMonth(this->month);

    ui->lineEdit_foodCostChanged->clear();
    ui->lineEdit_rentCostChanged->clear();
    ui->lineEdit_entertainmentCostChanged->clear();
    ui->lineEdit_tuitionCostChanged->clear();
    ui->lineEdit_savingsCostChanged->clear();
    ui->lineEdit_miscCostChanged->clear();

    this->updateBalance();
}

void AppDialog::on_comboBox_monthBudget_currentIndexChanged(int index)
{
    this->setMonth(index);
    this->_user->getAccount()->setMonth(this->month);

    ui->lineEdit_foodBudgetChanged->clear();
    ui->lineEdit_rentBudgetChanged->clear();
    ui->lineEdit_entertainmentBudgetChanged->clear();
    ui->lineEdit_tuitionBudgetChanged->clear();
    ui->lineEdit_savingsBudgetChanged->clear();
    ui->lineEdit_miscBudgetChanged->clear();

    this->updateBudget();
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

void AppDialog::on_pushButton_withdrawFoodB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_foodBudgetChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("FOODBUDGET");

    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
        this->updateBudget();
    }


}

void AppDialog::on_pushButton_depositRentB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_rentBudgetChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("RENTBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
}

void AppDialog::on_pushButton_withdrawRentB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_rentBudgetChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("RENTBUDGET");

    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
        this->updateBudget();
    }
}

void AppDialog::on_pushButton_depositEntertainmentB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_entertainmentBudgetChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
}

void AppDialog::on_pushButton_withdrawEntertainmentB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_entertainmentBudgetChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");

    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
        this->updateBudget();
    }
}

void AppDialog::on_pushButton_depositTuitionB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_tuitionBudgetChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
}

void AppDialog::on_pushButton_withdrawTuitionB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_tuitionBudgetChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("TUITIONBUDGET");


    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
        this->updateBudget();
    }
}

void AppDialog::on_pushButton_depositSavingsB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_savingsBudgetChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
}

void AppDialog::on_pushButton_withdrawSavingsB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_savingsBudgetChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");


    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
        this->updateBudget();
    }
}

void AppDialog::on_pushButton_depositMiscB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_miscBudgetChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("MISCBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
}

void AppDialog::on_pushButton_withdrawMiscB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_miscBudgetChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("MISCBUDGET");


    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
        this->updateBudget();
    }
}

void AppDialog::on_tabWidget_tabBarClicked(int index)
{
    if (index == 0 || index == 1) {
        ui->label_financialAdvice->show();
        ui->label_yearAdvice->hide();
    }
    else if (index == 2) {
        ui->label_financialAdvice->hide();

        //this->_user->getAccount()->fillArrayExpenses();

        std::string finAdvice = this->_user->getAccount()->getFinancialAdvice(-1); // -1 is to make it do year cost instead of monthly
        QString finAdviceQStr = QString::fromUtf8(finAdvice.c_str());

        ui->label_yearAdvice->setText(finAdviceQStr);
        ui->label_yearAdvice->repaint();

        ui->label_yearAdvice->show();
    }

}

void AppDialog::on_pushButton_makeBudget_clicked()
{
    QString totalAmt = ui->lineEdit_makeBudget->text();
    double totalAmtDouble = totalAmt.toDouble(); // Take in a total budget
    totalAmtDouble /= 12; // Split it into 12 months

    double foodAmt          = .15 * totalAmtDouble; // Make the proper percentages
    double rentAmt          = .30 * totalAmtDouble;
    double entertainmentAmt = .10 * totalAmtDouble;
    double tuitionAmt       = .20 * totalAmtDouble;
    double savingsAmt       = .05 * totalAmtDouble;
    double miscAmt          = .20 * totalAmtDouble;

    for(int i = 0; i < 12; i++){
        this->_user->getAccount()->setMonth(i);

        this->_user->getAccount()->setExpenseType("FOODBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("RENTBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("MISCBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
    }

    for(int i = 0; i < 12; i++){
        this->_user->getAccount()->setMonth(i);

        this->_user->getAccount()->setExpenseType("FOODBUDGET");
        this->_user->getAccount()->deposit(foodAmt);
        this->_user->getAccount()->setExpenseType("RENTBUDGET");
        this->_user->getAccount()->deposit(rentAmt);
        this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
        this->_user->getAccount()->deposit(entertainmentAmt);
        this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
        this->_user->getAccount()->deposit(tuitionAmt);
        this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
        this->_user->getAccount()->deposit(savingsAmt);
        this->_user->getAccount()->setExpenseType("MISCBUDGET");
        this->_user->getAccount()->deposit(miscAmt);
    }
    this->updateBalance();
    this->updateBudget();
}

void AppDialog::on_pushButton_clearBudget_clicked()
{
    for(int i = 0; i < 12; i++){
        this->_user->getAccount()->setMonth(i);

        this->_user->getAccount()->setExpenseType("FOODBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("RENTBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("MISCBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
    }
    this->updateBalance();
    this->updateBudget();
}

void AppDialog::on_pushButton_clearBalance_clicked()
{
    for(int i = 0; i < 12; i++){
        this->_user->getAccount()->setMonth(i);

        this->_user->getAccount()->setExpenseType("FOOD");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("RENT");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("ENTERTAINMENT");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("TUITION");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("SAVINGS");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("MISC");
        this->_user->getAccount()->changeExpenseField(0);
    }
    this->updateBalance();
    this->updateBudget();
}

void AppDialog::on_pushButton_makeBalance_clicked()
{
    double value;
    for(int i = 0; i < 12; i++){
        this->_user->getAccount()->setMonth(i);

        this->_user->getAccount()->setExpenseType("FOODBUDGET");
        value = this->_user->getAccount()->getExpense();
        this->_user->getAccount()->setExpenseType("FOOD");
        this->_user->getAccount()->changeExpenseField(value);

        this->_user->getAccount()->setExpenseType("RENTBUDGET");
        value = this->_user->getAccount()->getExpense();
        this->_user->getAccount()->setExpenseType("RENT");
        this->_user->getAccount()->changeExpenseField(value);

        this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
        value = this->_user->getAccount()->getExpense();
        this->_user->getAccount()->setExpenseType("ENTERTAINMENT");
        this->_user->getAccount()->changeExpenseField(value);

        this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
        value = this->_user->getAccount()->getExpense();
        this->_user->getAccount()->setExpenseType("TUITION");
        this->_user->getAccount()->changeExpenseField(value);

        this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
        value = this->_user->getAccount()->getExpense();
        this->_user->getAccount()->setExpenseType("SAVINGS");
        this->_user->getAccount()->changeExpenseField(value);

        this->_user->getAccount()->setExpenseType("MISCBUDGET");
        value = this->_user->getAccount()->getExpense();
        this->_user->getAccount()->setExpenseType("MISC");
        this->_user->getAccount()->changeExpenseField(value);
    }
    this->updateBalance();
    this->updateBudget();
}
