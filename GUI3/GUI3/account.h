#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "expenses.h"
#include "user.h"
#include "authenticator.h"
#include <map>
#include <vector>

class Account {

private:
    Expenses * expenses;
    string username;
    int month;
    string expenseType;

public:
    Account();
    void setUsername(string username);
    void setMonth(int month);
    void setExpenseType(string expenseType);
    void printData();
    void setCost(double amount);
    void changeExpenseField(double newAmount);
    bool dataExists();
    void writeData();
    void deposit(double depositAmount);
    void withdraw(double withdrawAmount);
    double getExpense();
    //void transfer(User * x, double transferAmount, string month, string expenseType, string thisUsername);
};


#endif // ACCOUNT_H
