#include "FinanceManager.h"


void FinanceManager::toRegisterUser()
{
    userManager.registration();
};

void FinanceManager::toLogUserIn()
{
    userManager.logIn();
    if (userManager.getIdOfLoggedUser()!=0)
    {
        incomeManager = new IncomeManager(userManager.getIdOfLoggedUser());
    };
};

bool FinanceManager::isUserLoggedIn()
{
    if(userManager.getIdOfLoggedUser()==0) return false;
    if(userManager.getIdOfLoggedUser()!=0) return true;
};

void FinanceManager::toChangePassword()
{
    userManager.passwordChange();
};

void FinanceManager::toLogUserOut()
{
    userManager.logOut();
    delete incomeManager;
    incomeManager = NULL;
};

void FinanceManager::toAddIncome()
{
    incomeManager -> addIncome();
};
