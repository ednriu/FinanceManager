#include "FinanceManager.h"


void FinanceManager::toRegisterUser()
{
    userManager.registration();
};

void FinanceManager::toLogUserIn()
{
    userManager.logIn();
    if (userManager.isUserLoggedIn())
    {
        incomeManager = new IncomeManager(userManager.getIdOfLoggedUser());
        expenceManager = new ExpenceManager(userManager.getIdOfLoggedUser());
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
    delete expenceManager;
    expenceManager = NULL;
};

void FinanceManager::toAddIncome()
{
    incomeManager -> addIncome();
};

void FinanceManager::toAddExpence()
{
    expenceManager -> addExpence();
};

int FinanceManager::showBalanceBetweenTwoDates()
{
    incomeManager -> showUsersIncomeWithinDataRange(0,0);
};

int FinanceManager::showBalanceForThatMonth()
{
    DateAuxiliaryMethods date1;
    DateAuxiliaryMethods date2;
    float balance;
    incomeManager ->readIncomesFromFileOfLoggedUser();
    expenceManager ->readExpencesFromFileOfLoggedUser();
    incomeManager ->showUsersIncomeWithinDataRange(date1.provideDataOfFirstDayThisMonth(), date2.provideDataOfToday());
    cout << endl;
    expenceManager ->showUsersExpenceWithinDataRange(date1.provideDataOfFirstDayThisMonth(), date2.provideDataOfToday());
    cout <<endl;
    balance = (incomeManager ->incomesInTotal(date1.provideDataOfFirstDayThisMonth(), date2.provideDataOfToday()))-(expenceManager->expencesInTotal(date1.provideDataOfFirstDayThisMonth(), date2.provideDataOfToday()));
    cout << "Bilans: "<< setprecision(2)<< balance<<"zl,"<<endl;
    incomeManager ->clearIncomes();
    expenceManager ->clearExpences();
    system("pause");
};

int FinanceManager::showBalanceForLastMonth()
{
    DateAuxiliaryMethods date1;
    DateAuxiliaryMethods date2;
    incomeManager ->showUsersIncomeWithinDataRange(date1.provideDataOfFirstDayMonthBefore(), date2.provideDataofLastDayMonthBefore());
};
