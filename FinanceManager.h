#ifndef FINANCEMANAGER_H_INCLUDED
#define FINANCEMANAGER_H_INCLUDED

#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenceManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FinanceManager
{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenceManager *expenceManager;
public:
    FinanceManager(string userFileName):userManager(userFileName)
    {
        incomeManager = NULL;
        expenceManager = NULL;
    };
    ~FinanceManager()
    {
        delete incomeManager;
        incomeManager = NULL;
        delete expenceManager;
        expenceManager = NULL;
    }
    void toRegisterUser();
    void toLogUserIn();
    bool isUserLoggedIn();
    void toChangePassword();
    void toLogUserOut();
    void toAddIncome();
    void toAddExpence();
    int showBalanceBetweenTwoDates();
    int showBalanceForThatMonth();
    int showBalanceForLastMonth();
};


#endif // FINANCEMANAGER_H_INCLUDED
