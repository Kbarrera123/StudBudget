#include "newwindow.h"
#include "ui_newwindow.h"
#include <QtCharts>
#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "expenses.h"

using namespace QtCharts;

newWindow::newWindow(Expenses* &expenses, QWidget *parent) :
    QMainWindow(parent),
    _expenses(expenses),
    ui(new Ui::newWindow)
{
    ui->setupUi(this);
    ui->centralwidget = new QWidget(this);
    this->setCentralWidget(ui->centralwidget);

    QChartView *foodChart = this->_expenses->getFoodGraph();
    QChartView *rentChart = this->_expenses->getRentGraph();
    QChartView *entertainmentChart = this->_expenses->getEntertainmentGraph();
    QChartView *savingsChart = this->_expenses->getSavingsGraph();
    QChartView *tuitionChart = this->_expenses->getTuitionGraph();
    QChartView *miscChart = this->_expenses->getMiscGraph();

    QGridLayout *gridLayout = new QGridLayout(ui->centralwidget);
    ui->centralwidget->setLayout(gridLayout);
    gridLayout->addWidget(foodChart, 0, 0, 1, 1);
    gridLayout->addWidget(rentChart, 0, 1, 1, 1);
    gridLayout->addWidget(entertainmentChart, 1, 1, 1, 1);
    gridLayout->addWidget(savingsChart, 1, 0, 1, 1);
    gridLayout->addWidget(tuitionChart, 0, 2, 1, 1);
    gridLayout->addWidget(miscChart, 1, 2, 1, 1);

}

newWindow::~newWindow()
{
    delete ui;
}

void newWindow::on_pushButton_clicked()
{
    this->hide();
}
