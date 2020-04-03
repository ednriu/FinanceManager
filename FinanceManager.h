#ifndef FINANCEMANAGER_H_INCLUDED
#define FINANCEMANAGER_H_INCLUDED

#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"

using namespace std;

class FinanceManager
{
    UserManager userManager;
    IncomeManager *incomeManager;
public:
    FinanceManager(string userFileName):userManager(userFileName)
    {
        incomeManager = NULL;
    };
    ~FinanceManager()
    {
        delete incomeManager;
        incomeManager = NULL;
    }
    void toRegisterUser();
    void toLogUserIn();
    bool isUserLoggedIn();
    void toChangePassword();
    void toLogUserOut();
    void toAddIncome();
};


#endif // FINANCEMANAGER_H_INCLUDED
