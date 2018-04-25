#include "appdialog.h"
#include "ui_appdialog.h"
#include <QMessageBox>
#include "newwindow.h"
#include <QtCharts>
#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

using namespace QtCharts;

AppDialog::AppDialog(User* &user, QWidget *parent) :
    QDialog(parent),
    _user(user),
    ui(new Ui::AppDialog)
{
    ui->setupUi(this);

    ui->comboBox_setAdviceMonth->addItem("January");
    ui->comboBox_setAdviceMonth->addItem("February");
    ui->comboBox_setAdviceMonth->addItem("March");
    ui->comboBox_setAdviceMonth->addItem("April");
    ui->comboBox_setAdviceMonth->addItem("May");
    ui->comboBox_setAdviceMonth->addItem("June");
    ui->comboBox_setAdviceMonth->addItem("July");
    ui->comboBox_setAdviceMonth->addItem("August");
    ui->comboBox_setAdviceMonth->addItem("September");
    ui->comboBox_setAdviceMonth->addItem("October");
    ui->comboBox_setAdviceMonth->addItem("November");
    ui->comboBox_setAdviceMonth->addItem("December");

    ui->comboBox_month->addItem("January");
    ui->comboBox_month->addItem("February");
    ui->comboBox_month->addItem("March");
    ui->comboBox_month->addItem("April");
    ui->comboBox_month->addItem("May");
    ui->comboBox_month->addItem("June");
    ui->comboBox_month->addItem("July");
    ui->comboBox_month->addItem("August");
    ui->comboBox_month->addItem("September");
    ui->comboBox_month->addItem("October");
    ui->comboBox_month->addItem("November");
    ui->comboBox_month->addItem("December");

    ui->tabWidget->setCurrentIndex(0);

    string username = user->getUsername();
    QString userQStr = QString::fromUtf8((username + '!').c_str());
    ui->label_getUsername->setText(userQStr);

    user->getAccount()->setUsername(username);
    user->getAccount()->writeData();
    user->getAccount()->setProjectedBudget();

    this->updateAll();
    Expenses *expenses = this->_user->getAccount()->getExpenseObj();

    QChartView *foodChart = expenses->getFoodGraph();
    QChartView *rentChart = expenses->getRentGraph();
    QChartView *entertainmentChart = expenses->getEntertainmentGraph();
    QChartView *savingsChart = expenses->getSavingsGraph();
    QChartView *tuitionChart = expenses->getTuitionGraph();
    QChartView *miscChart = expenses->getMiscGraph();
    QChartView *stackedChart = expenses->getExtraDeficitGraphYear();

    QGridLayout *yearGridLayout = new QGridLayout(ui->groupBox_yearlyGraphs);
    QGridLayout *gridLayout = new QGridLayout(ui->groupBox_graphs);
    ui->groupBox_graphs->setLayout(gridLayout);
    ui->groupBox_yearlyGraphs->setLayout(yearGridLayout);

    gridLayout->addWidget(foodChart, 0, 0, 1, 1);
    gridLayout->addWidget(rentChart, 0, 1, 1, 1);
    gridLayout->addWidget(entertainmentChart, 1, 1, 1, 1);
    gridLayout->addWidget(savingsChart, 1, 0, 1, 1);
    gridLayout->addWidget(tuitionChart, 0, 2, 1, 1);
    gridLayout->addWidget(miscChart, 1, 2, 1, 1);
    yearGridLayout->addWidget(stackedChart, 1, 1);
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

void AppDialog::updateAll(){
    for (int i = 0; i < 12; i++) {
        this->setMonth(i);
        updateBudget();
        updateBalance();
    }
}

void AppDialog::updateBudget(){
    this->_user->getAccount()->setMonth(this->month);

    this->_user->getAccount()->setExpenseType("FOODBUDGET");
    double foodBudget = this->_user->getAccount()->getExpense();
    ui->label_foodBudget_3->setText(QString::number(foodBudget));
    ui->label_foodBudget_3->repaint();

    this->_user->getAccount()->setExpenseType("RENTBUDGET");
    double rentBudget = this->_user->getAccount()->getExpense();
    ui->label_rentBudget_3->setText(QString::number(rentBudget));
    ui->label_rentBudget_3->repaint();

    this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
    double entertainmentBudget = this->_user->getAccount()->getExpense();
    ui->label_entertainmentBudget_3->setText(QString::number(entertainmentBudget));
    ui->label_entertainmentBudget_3->repaint();

    this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
    double tuitionBudget = this->_user->getAccount()->getExpense();
    ui->label_tuitionBudget_3->setText(QString::number(tuitionBudget));
    ui->label_tuitionBudget_3->repaint();

    this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
    double savingsBudget = this->_user->getAccount()->getExpense();
    ui->label_savingsBudget_3->setText(QString::number(savingsBudget));
    ui->label_savingsBudget_3->repaint();

    this->_user->getAccount()->setExpenseType("MISCBUDGET");
    double miscBudget = this->_user->getAccount()->getExpense();
    ui->label_miscBudget_3->setText(QString::number(miscBudget));
    ui->label_miscBudget_3->repaint();
}

void AppDialog::updateBalance(){
    this->_user->getAccount()->setMonth(this->month);

    this->_user->getAccount()->setExpenseType("FOOD");
    double foodCost = this->_user->getAccount()->getExpense();
    ui->label_foodCost->setText(QString::number(foodCost));
    ui->label_foodCost->repaint();

    this->_user->getAccount()->setExpenseType("RENT");
    double rentCost = this->_user->getAccount()->getExpense();
    ui->label_rentCost->setText(QString::number(rentCost));
    ui->label_rentCost->repaint();

    this->_user->getAccount()->setExpenseType("ENTERTAINMENT");
    double entertainmentCost = this->_user->getAccount()->getExpense();
    ui->label_entertainmentCost->setText(QString::number(entertainmentCost));
    ui->label_entertainmentCost->repaint();

    this->_user->getAccount()->setExpenseType("TUITION");
    double tuitionCost = this->_user->getAccount()->getExpense();
    ui->label_tuitionCost->setText(QString::number(tuitionCost));
    ui->label_tuitionCost->repaint();

    this->_user->getAccount()->setExpenseType("SAVINGS");
    double savingsCost = this->_user->getAccount()->getExpense();
    ui->label_savingsCost->setText(QString::number(savingsCost));
    ui->label_savingsCost->repaint();

    this->_user->getAccount()->setExpenseType("MISC");
    double miscCost = this->_user->getAccount()->getExpense();
    ui->label_miscCost->setText(QString::number(miscCost));
    ui->label_miscCost->repaint();
}

void AppDialog::on_comboBox_month_currentIndexChanged(int index)
{
    this->setMonth(index);
    this->_user->getAccount()->setMonth(this->month);

    ui->lineEdit_foodCostChanged->clear();
    ui->lineEdit_rentCostChanged->clear();
    ui->lineEdit_entertainmentCostChanged->clear();
    ui->lineEdit_tuitionCostChanged->clear();
    ui->lineEdit_savingsCostChanged->clear();
    ui->lineEdit_miscCostChanged->clear();
    ui->lineEdit_foodBudgetChanged_3->clear();
    ui->lineEdit_rentBudgetChanged_3->clear();
    ui->lineEdit_entertainmentBudgetChanged_3->clear();
    ui->lineEdit_tuitionBudgetChanged_3->clear();
    ui->lineEdit_savingsBudgetChanged_3->clear();
    ui->lineEdit_miscBudgetChanged_3->clear();

    this->updateBalance();
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

    QString depositAmt = ui->lineEdit_foodBudgetChanged_3->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("FOODBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
}

void AppDialog::on_pushButton_withdrawFoodB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_foodBudgetChanged_3->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("FOODBUDGET");

    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBudget();
}

void AppDialog::on_pushButton_depositRentB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_rentBudgetChanged_3->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("RENTBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
}

void AppDialog::on_pushButton_withdrawRentB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_rentBudgetChanged_3->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("RENTBUDGET");

    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBudget();
}

void AppDialog::on_pushButton_depositEntertainmentB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_entertainmentBudgetChanged_3->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
}

void AppDialog::on_pushButton_withdrawEntertainmentB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_entertainmentBudgetChanged_3->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");

    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBudget();
}

void AppDialog::on_pushButton_depositTuitionB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_tuitionBudgetChanged_3->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
}

void AppDialog::on_pushButton_withdrawTuitionB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_tuitionBudgetChanged_3->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("TUITIONBUDGET");


    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBudget();
}

void AppDialog::on_pushButton_depositSavingsB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_savingsBudgetChanged_3->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
}

void AppDialog::on_pushButton_withdrawSavingsB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_savingsBudgetChanged_3->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");


    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBudget();
}

void AppDialog::on_pushButton_depositMiscB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_miscBudgetChanged_3->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("MISCBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
}

void AppDialog::on_pushButton_withdrawMiscB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_miscBudgetChanged_3->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("MISCBUDGET");


    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBudget();
}

void AppDialog::on_tabWidget_tabBarClicked(int index)
{
    if (index == 1) {

        this->updateBudget();
        this->updateBalance();



        //foodChart->repaint();
    }
    else if (index == 2) {
        ui->label_yearAdvice->hide();
        ui->label_financialAdvice->hide();

        this->updateBalance();
        this->updateBudget();

        std::string yearlyFinAdvice = this->_user->getAccount()->getFinancialAdvice(-1); // -1 is to make it do year cost instead of monthly
        QString yearlyFinAdviceQStr = QString::fromUtf8(yearlyFinAdvice.c_str());

        ui->label_yearAdvice->setText(yearlyFinAdviceQStr);
        ui->label_yearAdvice->repaint();
        ui->label_yearAdvice->show();

        this->setMonth(ui->comboBox_setAdviceMonth->currentIndex()); //set month to current dropdown index

        std::string finAdvice = this->_user->getAccount()->getFinancialAdvice(this->month);
        QString finAdviceQStr = QString::fromUtf8(finAdvice.c_str());

        ui->label_financialAdvice->clear();
        ui->label_financialAdvice->setText(finAdviceQStr);
        ui->label_financialAdvice->repaint();
        ui->label_financialAdvice->show();
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
    this->_user->getAccount()->setProjectedBudget();
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
