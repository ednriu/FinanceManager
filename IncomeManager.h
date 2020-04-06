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

    void readAllIncomesFromFile();
    const int ID_OF_LOGGED_USER;
    vector<FinancialData> incomes;


protected:
    int dateInput();
    int moneyInput();
    string categoryInput();
    float getPLNfromInt(int moneyInt);
    void sortVectorWithFinancialDataAccordingToDate(vector<FinancialData> &vectorToBeSorted);
    float sumUpVectorWithFinancialDataWithinDataRange(vector<FinancialData> &vectorToBeSummed, int date1, int date2);
    void theLoopCoutsVectorOfFinancialDataWithinDates(vector<FinancialData> &vectorToBeCouted, int date1, int date2);
    float replaceCommaWithDot(string text);


public:
    IncomeManager(int id_of_logged_user):ID_OF_LOGGED_USER(id_of_logged_user)
    {

    };

    void addIncome();
    void showUsersIncomeWithinDataRange(int date1, int date2);
    float incomesInTotal(int date1, int date2);
    void readIncomesFromFileOfLoggedUser();
    void clearIncomes();

};

#endif // INCOMEMANAGER_H_INCLUDED
