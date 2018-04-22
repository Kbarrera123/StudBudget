#include "expenses.h"
#include <string>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts>
/*
Expenses::Expenses(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Expenses)
{
    ui->setupUi(this);
}

Expenses::~Expenses()
{
    delete ui;
}
*/
Expenses::Expenses(int num) {
    for(int i = 0; i < 12; i++) {
        foodCost[i] = 0;
        foodBudget[i] = 0;
        rentCost[i] = 0;
        rentBudget[i] = 0;
        entertainmentCost[i] = 0;
        entertainmentBudget[i] = 0;
        tuitionCost[i] = 0;
        tuitionBudget[i] = 0;
        savingsCost[i] = 0;
        savingsBudget[i] = 0;
        miscCost[i] = 0;
        miscBudget[i] = 0;
    }
}

void Expenses::fillArrays(double* f, double* r, double* e, double* t, double* s, double* m, double* fBudget, double* rBudget, double* eBudget, double* tBudget, double* sBudget, double* mBudget) {
    for(int i = 0; i < 12; i++) {
        foodCost[i] = f[i];
        foodBudget[i] = fBudget[i];
        rentCost[i] = r[i];
        rentBudget[i] = rBudget[i];
        entertainmentCost[i] = e[i];
        entertainmentBudget[i] = eBudget[i];
        tuitionCost[i] = t[i];
        tuitionBudget[i] = tBudget[i];
        savingsCost[i] = s[i];
        savingsBudget[i] = sBudget[i];
        miscCost[i] = m[i];
        miscBudget[i] = mBudget[i];
    }
}

void Expenses::setFoodCost(double food, int month) {
  foodCost[month] = food;
  totalCost[month] += food;
}

double Expenses::getFoodCost(int month) {
  return foodCost[month];
}

void Expenses::getFoodGraph(){ // annual food spending line graph
  // set foodGraph data
   QLineSeries *foodGraph = new QLineSeries();
   for(int i = 0; i < 12; i++) {
     foodGraph->append(i + 1, getFoodCost(i));
   }

  // make food graph
  QChart *foodChart = new QChart();
  foodChart->legend()->hide();
  foodChart->addSeries(foodGraph);
  foodChart->createDefaultAxes();
  foodChart->setTitle("Food Spending");

  // view food graph
  QChartView *foodView = new QChartView(foodChart);
  foodView->setRenderHint(QPainter::Antialiasing);
  QMainWindow window;
  window.setCentralWidget(foodView);
  window.resize(400, 300);
  window.show();
}

void Expenses::setFoodBudget(double food, int month) {
  foodBudget[month] = food;
  totalBudget[month] += food;
}

double Expenses::getFoodBudget(int month) {
  return foodBudget[month];
}

void Expenses::setRentCost(double rent, int month) {
  rentCost[month] = rent;
  totalCost[month] += rent;
}

double Expenses::getRentCost(int month) {
  return foodCost[month];
}

void Expenses::getRentGraph() { // annual rent spending line graph
  // set rentGraph data
   QLineSeries *rentGraph = new QLineSeries();
   for(int i = 0; i < 12; i++) {
     rentGraph->append(i + 1, getRentCost(i));
   }

  // make rent graph
  QChart *rentChart = new QChart();
  rentChart->legend()->hide();
  rentChart->addSeries(rentGraph);
  rentChart->createDefaultAxes();
  rentChart->setTitle("Rent Spending");

  // view rent graph
  QChartView *rentView = new QChartView(rentChart);
  rentView->setRenderHint(QPainter::Antialiasing);
  QMainWindow window;
  window.setCentralWidget(rentView);
  window.resize(400, 300);
  window.show();
}

void Expenses::setRentBudget(double rent, int month) {
  rentBudget[month] = rent;
  totalBudget[month] += rent;
}

double Expenses::getRentBudget(int month) {
  return foodBudget[month];
}

void Expenses::setEntertainmentCost(double entertainment, int month) {
  entertainmentCost[month] = entertainment;
  totalCost[month] += entertainment;
}

double Expenses::getEntertainmentCost(int month) {
  return entertainmentCost[month];
}

void Expenses::getEntertainmentGraph() { // annual entertainment spending line graph
  // set entertainmentGraph data
   QLineSeries *entertainmentGraph = new QLineSeries();
   for(int i = 0; i < 12; i++) {
     entertainmentGraph->append(i + 1, getEntertainmentCost(i));
   }

  // make entertainment graph
  QChart *entertainmentChart = new QChart();
  entertainmentChart->legend()->hide();
  entertainmentChart->addSeries(entertainmentGraph);
  entertainmentChart->createDefaultAxes();
  entertainmentChart->setTitle("Entertainment Spending");

  // view entertainment graph
  QChartView *entertainmentView = new QChartView(entertainmentChart);
  entertainmentView->setRenderHint(QPainter::Antialiasing);
  QMainWindow window;
  window.setCentralWidget(entertainmentView);
  window.resize(400, 300);
  window.show();
}

void Expenses::setEntertainmentBudget(double entertainment, int month) {
  entertainmentBudget[month] = entertainment;
  totalBudget[month] += entertainment;
}

double Expenses::getEntertainmentBudget(int month) {
  return entertainmentBudget[month];
}

void Expenses::setTuitionCost(double tuition, int month) {
  tuitionCost[month] = tuition;
  totalCost[month] += tuition;
}

double Expenses::getTuitionCost(int month) {
  return tuitionCost[month];
}

void Expenses::getTuitionGraph() { // annual tuition spending line graph
  // set tuitionGraph data
   QLineSeries *tuitionGraph = new QLineSeries();
   for(int i = 0; i < 12; i++) {
     tuitionGraph->append(i + 1, getTuitionCost(i));
   }

  // make tuition graph
  QChart *tuitionChart = new QChart();
  tuitionChart->legend()->hide();
  tuitionChart->addSeries(tuitionGraph);
  tuitionChart->createDefaultAxes();
  tuitionChart->setTitle("Tuition Spending");

  // view tuition graph
  QChartView *tuitionView = new QChartView(tuitionChart);
  tuitionView->setRenderHint(QPainter::Antialiasing);
  QMainWindow window;
  window.setCentralWidget(tuitionView);
  window.resize(400, 300);
  window.show();
}

void Expenses::setTuitionBudget(double tuition, int month) {
  tuitionBudget[month] = tuition;
  totalBudget[month] += tuition;
}

double Expenses::getTuitionBudget(int month) {
  return tuitionBudget[month];
}

void Expenses::setSavingsCost(double savings, int month) {
  savingsCost[month] = savings;
  totalCost[month] += savings;
}

double Expenses::getSavingsCost(int month) {
  return savingsCost[month];
}

void Expenses::getSavingsGraph() { // annual savings spending line graph
  // set savingsGraph data
  QLineSeries *savingsGraph = new QLineSeries();
  for(int i = 0; i < 12; i++) {
    savingsGraph->append(i + 1, getSavingsCost(i));
  }

  // make savings graph
  QChart *savingsChart = new QChart();
  savingsChart->legend()->hide();
  savingsChart->addSeries(savingsGraph);
  savingsChart->createDefaultAxes();
  savingsChart->setTitle("Savings Spending");

  // view savings graph
  QChartView *savingsView = new QChartView(savingsChart);
  savingsView->setRenderHint(QPainter::Antialiasing);
  QMainWindow window;
  window.setCentralWidget(savingsView);
  window.resize(400, 300);
  window.show();
}

void Expenses::setSavingsBudget(double savings, int month) {
  savingsBudget[month] = savings;
  totalBudget[month] += savings;
}

double Expenses::getSavingsBudget(int month) {
  return savingsBudget[month];
}

void Expenses::setMiscCost(double misc, int month) {
  miscCost[month] = misc;
  totalCost[month] += misc;
}

double Expenses::getMiscCost(int month) {
  return miscCost[month];
}

void Expenses::getMiscGraph() { // annual misc spending line graph
  // set miscGraph data
   QLineSeries *miscGraph = new QLineSeries();
   for(int i = 0; i < 12; i++) {
     miscGraph->append(i + 1, getMiscCost(i));
   }

  // make misc graph
  QChart *miscChart = new QChart();
  miscChart->legend()->hide();
  miscChart->addSeries(miscGraph);
  miscChart->createDefaultAxes();
  miscChart->setTitle("Misc Spending");

  // view misc graph
  QChartView *miscView = new QChartView(miscChart);
  miscView->setRenderHint(QPainter::Antialiasing);
  QMainWindow window;
  window.setCentralWidget(miscView);
  window.resize(400, 300);
  window.show();
}

void Expenses::setMiscBudget(double misc, int month) {
  miscBudget[month] = misc;
  totalBudget[month] += misc;
}

double Expenses::getMiscBudget(int month) {
  return miscBudget[month];
}

void Expenses::setExtraDeficit() {
  for(int i = 0; i < 12; i++) {
    if(getFoodBudget(i) - getFoodCost(i) > 0) {
      foodExtra[i] = getFoodBudget(i) - getFoodCost(i);
      foodDeficit[i] = 0;
    } else if(getFoodBudget(i) - getFoodCost(i) == 0) {
      foodExtra[i] = 0;
      foodDeficit[i] = 0;
    } else {
      foodExtra[i] = 0;
      foodDeficit[i] = getFoodCost(i) - getFoodBudget(i);
    }

    if(getRentBudget(i) - getRentCost(i) > 0) {
      rentExtra[i] = getRentBudget(i) - getRentCost(i);
      rentDeficit[i] = 0;
    } else if(getRentBudget(i) - getRentCost(i) == 0) {
      rentExtra[i] = 0;
      rentDeficit[i] = 0;
    } else {
      rentExtra[i] = 0;
      rentDeficit[i] = getRentCost(i) - getRentBudget(i);
    }

    if(getEntertainmentBudget(i) - getEntertainmentCost(i) > 0) {
      entertainmentExtra[i] = getEntertainmentBudget(i) - getEntertainmentCost(i);
      entertainmentDeficit[i] = 0;
    } else if(getEntertainmentBudget(i) - getEntertainmentCost(i) == 0) {
      entertainmentExtra[i] = 0;
      entertainmentDeficit[i] = 0;
    } else {
      entertainmentExtra[i] = 0;
      entertainmentDeficit[i] = getEntertainmentCost(i) - getEntertainmentBudget(i);
    }

    if(getTuitionBudget(i) - getTuitionCost(i) > 0) {
      tuitionExtra[i] = getTuitionBudget(i) - getTuitionCost(i);
      tuitionDeficit[i] = 0;
    } else if(getTuitionBudget(i) - getTuitionCost(i) == 0) {
      tuitionExtra[i] = 0;
      tuitionDeficit[i] = 0;
    } else {
      tuitionExtra[i] = 0;
      tuitionDeficit[i] = getTuitionCost(i) - getTuitionBudget(i);
    }

    if(getSavingsBudget(i) - getSavingsCost(i) > 0) {
      savingsExtra[i] = getSavingsBudget(i) - getSavingsCost(i);
      savingsDeficit[i] = 0;
    } else if(getSavingsBudget(i) - getSavingsCost(i) == 0) {
      savingsExtra[i] = 0;
      savingsDeficit[i] = 0;
    } else {
      savingsExtra[i] = 0;
      savingsDeficit[i] = getSavingsCost(i) - getSavingsBudget(i);
    }

    if(getMiscBudget(i) - getMiscCost(i) > 0) {
      miscExtra[i] = getMiscBudget(i) - getMiscCost(i);
      miscDeficit[i] = 0;
    } else if(getMiscBudget(i) - getMiscCost(i) == 0) {
      miscExtra[i] = 0;
      miscDeficit[i] = 0;
    } else {
      miscExtra[i] = 0;
      miscDeficit[i] = getMiscCost(i) - getMiscBudget(i);
    }

    totalFoodCost += foodCost[i];
    totalFoodBudget += foodBudget[i];
    totalFoodExtra += foodExtra[i];
    totalFoodDeficit += foodDeficit[i];
    totalRentCost += rentCost[i];
    totalRentBudget += rentBudget[i];
    totalRentExtra += rentExtra[i];
    totalRentDeficit += rentDeficit[i];
    totalEntertainmentCost += entertainmentCost[i];
    totalEntertainmentBudget += entertainmentBudget[i];
    totalEntertainmentExtra += entertainmentExtra[i];
    totalEntertainmentDeficit += entertainmentDeficit[i];
    totalTuitionCost += tuitionCost[i];
    totalTuitionBudget += tuitionBudget[i];
    totalTuitionExtra += tuitionExtra[i];
    totalTuitionDeficit += tuitionDeficit[i];
    totalSavingsCost += savingsCost[i];
    totalSavingsBudget += savingsBudget[i];
    totalSavingsExtra += savingsExtra[i];
    totalSavingsDeficit += savingsDeficit[i];
    totalMiscCost += miscCost[i];
    totalMiscBudget += miscBudget[i];
    totalMiscExtra += miscExtra[i];
    totalMiscDeficit += miscDeficit[i];
  }
}

void Expenses::getAnnualCostChart() { // expenses pie chart by year
  QPieSeries *series = new QPieSeries();
  series->append("Food", totalFoodCost);
  series->append("Rent", totalRentCost);
  series->append("Entertainment", totalEntertainmentCost);
  series->append("Tuition", totalTuitionCost);
  series->append("Savings", totalSavingsCost);
  series->append("Misc", totalMiscCost);

  QPieSlice *slice0 = series->slices().at(0);
  slice0->setLabelVisible();
  slice0->setPen(QPen(Qt::darkRed, 2));
  slice0->setBrush(Qt::red);
  QPieSlice *slice1 = series->slices().at(1);
  slice1->setLabelVisible();
  slice1->setPen(QPen(Qt::darkGreen, 2));
  slice1->setBrush(Qt::green);
  QPieSlice *slice2 = series->slices().at(2);
  slice2->setLabelVisible();
  slice2->setPen(QPen(Qt::darkBlue, 2));
  slice2->setBrush(Qt::blue);
  QPieSlice *slice3 = series->slices().at(3);
  slice3->setLabelVisible();
  slice3->setPen(QPen(Qt::darkCyan, 2));
  slice3->setBrush(Qt::cyan);
  QPieSlice *slice4 = series->slices().at(4);
  slice4->setLabelVisible();
  slice4->setPen(QPen(Qt::darkMagenta, 2));
  slice4->setBrush(Qt::magenta);
  QPieSlice *slice5 = series->slices().at(5);
  slice5->setLabelVisible();
  slice5->setPen(QPen(Qt::darkYellow, 2));
  slice5->setBrush(Qt::yellow);

  QChart *chart = new QChart();
  chart->addSeries(series);
  chart->setTitle("Annual Spending");
  chart->legend()->hide();

  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);

  QMainWindow window;
  window.setCentralWidget(chartView);
  window.resize(400, 300);
  window.show();
}

void Expenses::getMonthCostChart(int month) { // expenses pie chart by month
  QPieSeries *series = new QPieSeries();
  series->append("Food", foodCost[month]);
  series->append("Rent", rentCost[month]);
  series->append("Entertainment", entertainmentCost[month]);
  series->append("Tuition", tuitionCost[month]);
  series->append("Savings", savingsCost[month]);
  series->append("Misc", miscCost[month]);

  QPieSlice *slice0 = series->slices().at(0);
  slice0->setLabelVisible();
  slice0->setPen(QPen(Qt::darkRed, 2));
  slice0->setBrush(Qt::red);
  QPieSlice *slice1 = series->slices().at(1);
  slice1->setLabelVisible();
  slice1->setPen(QPen(Qt::darkGreen, 2));
  slice1->setBrush(Qt::green);
  QPieSlice *slice2 = series->slices().at(2);
  slice2->setLabelVisible();
  slice2->setPen(QPen(Qt::darkBlue, 2));
  slice2->setBrush(Qt::blue);
  QPieSlice *slice3 = series->slices().at(3);
  slice3->setLabelVisible();
  slice3->setPen(QPen(Qt::darkCyan, 2));
  slice3->setBrush(Qt::cyan);
  QPieSlice *slice4 = series->slices().at(4);
  slice4->setLabelVisible();
  slice4->setPen(QPen(Qt::darkMagenta, 2));
  slice4->setBrush(Qt::magenta);
  QPieSlice *slice5 = series->slices().at(5);
  slice5->setLabelVisible();
  slice5->setPen(QPen(Qt::darkYellow, 2));
  slice5->setBrush(Qt::yellow);

  QChart *chart = new QChart();
  chart->addSeries(series);
  chart->setTitle("Monthly Spending");
  chart->legend()->hide();

  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);

  QMainWindow window;
  window.setCentralWidget(chartView);
  window.resize(400, 300);
  window.show();
}

void Expenses::getExtraDeficitGraphYear() { // expenses bar chart by year
  setExtraDeficit();

  QBarSet *set0 = new QBarSet("Under budet spending");
  QBarSet *set1 = new QBarSet("Unused budget");
  QBarSet *set2 = new QBarSet("Over budget spending");

  *set0 << totalFoodCost << totalRentCost << totalEntertainmentCost << totalTuitionCost << totalSavingsCost << totalMiscCost;
  *set1 << totalFoodExtra << totalRentExtra << totalEntertainmentExtra << totalTuitionExtra << totalSavingsExtra << totalMiscExtra;
  *set2 << totalFoodDeficit << totalRentDeficit << totalEntertainmentDeficit << totalTuitionDeficit << totalSavingsDeficit << totalMiscDeficit;

  set0->setBrush(Qt::gray);
  set1->setBrush(Qt::green);
  set2->setBrush(Qt::red);

  QStackedBarSeries *series = new QStackedBarSeries();
  series->append(set0);
  series->append(set1);
  series->append(set2);

  QChart *chart = new QChart();
  chart->addSeries(series);
  chart->setTitle("Deficit Spending by Year");
  chart->setAnimationOptions(QChart::SeriesAnimations);

  QStringList categories;
  categories << "Food" << "Rent" << "Entertainment" << "Tuition" << "Savings" << "Misc";
  QBarCategoryAxis *axis = new QBarCategoryAxis();
  axis->append(categories);
  chart->createDefaultAxes();
  chart->setAxisX(axis, series);

  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);

  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);

  QMainWindow window;
   window.setCentralWidget(chartView);
   window.resize(420, 300);
   window.show();
}

void Expenses::getExtraDeficitGraphMonth(int month) { // expenses bar chart by month
  setExtraDeficit();

  QBarSet *set0 = new QBarSet("Under budet spending");
  QBarSet *set1 = new QBarSet("Unused budget");
  QBarSet *set2 = new QBarSet("Over budget spending");

  *set0 << foodCost[month] << rentCost[month] << entertainmentCost[month] << tuitionCost[month] << savingsCost[month] << miscCost[month];
  *set1 << foodExtra[month] << rentExtra[month] << entertainmentExtra[month] << tuitionExtra[month] << savingsExtra[month] << miscExtra[month];
  *set2 << foodDeficit[month] << rentDeficit[month] << entertainmentDeficit[month] << tuitionDeficit[month] << savingsDeficit[month] << miscDeficit[month];

  set0->setBrush(Qt::gray);
  set1->setBrush(Qt::green);
  set2->setBrush(Qt::red);

  QStackedBarSeries *series = new QStackedBarSeries();
  series->append(set0);
  series->append(set1);
  series->append(set2);

  QChart *chart = new QChart();
  chart->addSeries(series);
  chart->setTitle("Deficit Spending in Month");
  chart->setAnimationOptions(QChart::SeriesAnimations);

  QStringList categories;
  categories << "Food" << "Rent" << "Entertainment" << "Tuition" << "Savings" << "Misc";
  QBarCategoryAxis *axis = new QBarCategoryAxis();
  axis->append(categories);
  chart->createDefaultAxes();
  chart->setAxisX(axis, series);

  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);

  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);

  QMainWindow window;
  window.setCentralWidget(chartView);
  window.resize(420, 300);
  window.show();
}

std::string Expenses::financialAdvice() {
    std::string concatAdvice = "";
        if(totalFoodDeficit > 0){
        concatAdvice += "It is recommended to spend no more than 15% on Food\n";
        }
        if(totalRentDeficit > 0){
        concatAdvice += "Remember, put 30% of your income towards Rent this month\n";
        }
        if(totalEntertainmentDeficit > 0){
        concatAdvice += "Prioritize your spending! Your Entertainment costs have exceeded 10%\n";
        }
        if(totalTuitionExtra > 0) {
        concatAdvice += "Delegate 20% of your income to Tuition this month to avoid student loan debt!\n";
        }
        if(totalTuitionDeficit > 0) {
        concatAdvice += "Only 20% of your income should be spent on Tuition\n";
        }
        if(totalSavingsDeficit > 0) {
        concatAdvice += "Your Savings are low, make sure to save at least 5% of your income this month!\n";
        }
        if(totalMiscDeficit > 0) {
        concatAdvice += "Miscellaneous costs like clothing or transportation shouldn't exceed 20% of your income. Shop smart!\n";
        }
        if(totalAnnualExtra > 0){
        concatAdvice += "You have some extra total money! Add it to Savings!\n";
        }
        if((totalFoodBudget/totalAnnualBudget) > .17
        || (totalRentBudget/totalAnnualBudget) > .33
        || (totalEntertainmentBudget/totalAnnualBudget) > .12
        || (totalTuitionBudget/totalAnnualBudget) > .22
        || (totalMiscBudget/totalAnnualBudget) > .22){
        concatAdvice += "Too much of your budget is in  \n";
        }

        concatAdvice += "Treat yourself, but don't overspend\n";
        return concatAdvice;
}
