#ifndef INCOMEMANAGER_H_INCLUDED
#define INCOMEMANAGER_H_INCLUDED
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "DataFile.h"
#include "DateAuxiliaryMethods.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeManager
{
    const string INCOME_FILE_NAME = "Incomes";
    const int ID_OF_LOGGED_USER;
    vector<FinancialData> incomes;
    int dateInput();
    int moneyInput();
    string categoryInput();
    float getPLNfromInt(int moneyInt);
    void sortIncomesAccordingToDate();
    float sumUpUserIncomesWithinDataRange(int date1, int date2);
    void readAllIncomesFromFile();
    void readIncomesFromFileOfLoggedUser();
    void theLoopCoutsIncomesWithinDates(int date1, int date2);
    float replaceCommaWithDot(string text);

public:
    IncomeManager(int id_of_logged_user):ID_OF_LOGGED_USER(id_of_logged_user)
    {};

    void addIncome();
    void showUsersIncomeWithinDataRange(int date1, int date2);

};

#endif // INCOMEMANAGER_H_INCLUDED
