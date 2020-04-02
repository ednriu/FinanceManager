#ifndef INCOMEMANAGER_H_INCLUDED
#define INCOMEMANAGER_H_INCLUDED
#include <iostream>

#include "DataFile.h"
#include "DateAuxiliaryMethods.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeManager
{
    const string INCOME_FILE_NAME = "Incomes";
    const int ID_OF_LOGGED_USER = 2;
    vector<FinancialData> incomes;
    int dateInput();
    int moneyInput();
    string categoryInput();
public:
    IncomeManager()
    {
        /*for(vector <FinancialData> :: iterator it = incomes.begin(); it != incomes.end(); ++it)
        {
           cout << (*it).getCategory()<<endl;
        }*/
    };
    void readAllIncomesFromFile();
    void readIncomesFromFileOfOneUser();
    void addIncome();
};

#endif // INCOMEMANAGER_H_INCLUDED
