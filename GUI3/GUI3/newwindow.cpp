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
/*
    QChart *chart = new QChart;
    QChartView *chartView = new QChartView(chart);
    QGridLayout *gridLayout = new QGridLayout(ui->centralwidget);
    gridLayout->addWidget(chartView, 0, 0); */

    QChartView *foodChart = this->_expenses->getFoodGraph();
    foodChart->resize(400,300);
    this->setCentralWidget(foodChart);
    //this->resize(400, 300);
    this->lower();
}

newWindow::~newWindow()
{
    delete ui;
}

void newWindow::on_pushButton_clicked()
{
    this->hide();
}
