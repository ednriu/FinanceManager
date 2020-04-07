#ifndef EXPENCEMANAGER_H_INCLUDED
#define EXPENCEMANAGER_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "DataFile.h"
#include "DateAuxiliaryMethods.h"
#include "AuxiliaryMethods.h"
#include "IncomeManager.h"

using namespace std;

class ExpenceManager : private IncomeManager
{
    const string EXPENCE_FILE_NAME = "Expences";
    const int ID_OF_LOGGED_USER;
    vector<FinancialData> expences;
    int idOfLastUser=0;

    void readAllExpencesFromFile();


public:

    ExpenceManager(int idOfLoggedUser) : IncomeManager(idOfLoggedUser), ID_OF_LOGGED_USER(idOfLoggedUser)
    {
    //expences = &IncomeManager::incomes;
    };
    void readExpencesFromFileOfLoggedUser();
    void addExpence();
    void showUsersExpenceWithinDataRange(int date1, int date2);
    float expencesInTotal(int date1, int date2);
    void clearExpences();
};

#endif // EXPENCEMANAGER_H_INCLUDED
