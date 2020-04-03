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

int FinanceManager::showBalanceBetweenTwoDates()
{
    incomeManager -> showUsersIncomeWithinDataRange(0,0);
};

int FinanceManager::showBalanceForThatMonth()
{
    DateAuxiliaryMethods date1;
    DateAuxiliaryMethods date2;
    incomeManager ->showUsersIncomeWithinDataRange(date1.provideDataOfFirstDayThisMonth(), date2.provideDataOfToday());
};

int FinanceManager::showBalanceForLastMonth()
{
    DateAuxiliaryMethods date1;
    DateAuxiliaryMethods date2;
    incomeManager ->showUsersIncomeWithinDataRange(date1.provideDataOfFirstDayMonthBefore(), date2.provideDataofLastDayMonthBefore());
};
