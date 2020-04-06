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
    int date1, date2;
    DateAuxiliaryMethods dateAuxiliaryMethods;
    float balance;

    cout<<"Podaj date poczatkowa:"<<endl;
    date1 = incomeManager->dateInput();
    cout<<"Podaj date koncowa:"<<endl;
    date2 = incomeManager->dateInput();
    cout <<endl;

    system("cls");
    cout <<"Finanse od:"<<dateAuxiliaryMethods.convertDataIntegerToString(date1)<<" do: "<<dateAuxiliaryMethods.convertDataIntegerToString(date2)<<endl;
    incomeManager ->readIncomesFromFileOfLoggedUser();
    expenceManager ->readExpencesFromFileOfLoggedUser();
    incomeManager ->showUsersIncomeWithinDataRange(date1, date2);
    cout << endl;
    expenceManager ->showUsersExpenceWithinDataRange(date1, date2);
    cout <<endl;
    balance = (incomeManager ->incomesInTotal(date1, date2))-(expenceManager->expencesInTotal(date1, date2));
    cout << "Bilans: "<< setprecision(2)<< balance<<"zl,"<<endl;
    incomeManager ->clearIncomes();
    expenceManager ->clearExpences();
    system("pause");
};

int FinanceManager::showBalanceForThatMonth()
{
    AuxiliaryMethods auxiliaryMethods;
    DateAuxiliaryMethods date1;
    DateAuxiliaryMethods date2;
    float balance;

    system("cls");
    auxiliaryMethods.printHeader("Finanse z biezacego miesiaca:");
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
    AuxiliaryMethods auxiliaryMethods;
    DateAuxiliaryMethods date1;
    DateAuxiliaryMethods date2;
    float balance;

    system("cls");
    auxiliaryMethods.printHeader("Finanse z poprzedniego miesiaca:");
    incomeManager ->readIncomesFromFileOfLoggedUser();
    expenceManager ->readExpencesFromFileOfLoggedUser();
    incomeManager ->showUsersIncomeWithinDataRange(date1.provideDataOfFirstDayMonthBefore(), date2.provideDataofLastDayMonthBefore());
    cout << endl;
    expenceManager ->showUsersExpenceWithinDataRange(date1.provideDataOfFirstDayMonthBefore(), date2.provideDataofLastDayMonthBefore());
    cout <<endl;
    balance = (incomeManager ->incomesInTotal(date1.provideDataOfFirstDayMonthBefore(), date2.provideDataofLastDayMonthBefore()))-(expenceManager->expencesInTotal(date1.provideDataOfFirstDayMonthBefore(), date2.provideDataofLastDayMonthBefore()));
    cout << "Bilans: "<< setprecision(2)<< balance<<"zl,"<<endl;
    incomeManager ->clearIncomes();
    expenceManager ->clearExpences();
    system("pause");
};
