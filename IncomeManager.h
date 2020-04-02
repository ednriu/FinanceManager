#ifndef INCOMEMANAGER_H_INCLUDED
#define INCOMEMANAGER_H_INCLUDED
#include <iostream>

#include "DataFile.h"
#include "DateAuxiliaryMethods.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeManager
{
    const string INCOME_FILE_NAME;
    vector<FinancialData> incomes;
    int dateInput();
    int moneyInput();
    string categoryInput();
public:
    IncomeManager()
    {
        readIncomesFromFile("Incomes");
    };
    void readIncomesFromFile(string INCOME_FILE_NAME);
    void addIncome();
};

#endif // INCOMEMANAGER_H_INCLUDED
