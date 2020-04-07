#include "ExpenceManager.h"


void ExpenceManager::addExpence()
{
    FinancialData pieceOfData;
    DataFile fileWithExpences;
    DateAuxiliaryMethods dateOperator;
    string dataReader;

    readAllExpencesFromFile();

    system("cls");
    int dateTemp = IncomeManager::dateInput();
    pieceOfData.setDate(dateTemp);
    pieceOfData.setId(idOfLastUser+1);
    pieceOfData.setUserId(ID_OF_LOGGED_USER);
    pieceOfData.setCategory(categoryInput());
    pieceOfData.setMoneyAmmount(moneyInput());

    expences.push_back(pieceOfData);

    fileWithExpences.saveXmlFromVector(expences, EXPENCE_FILE_NAME);
    expences.clear();
}

void ExpenceManager::readAllExpencesFromFile()
{
    DataFile expencesFile;
    expences = expencesFile.loadXmlToVector(EXPENCE_FILE_NAME, ID_OF_LOGGED_USER, true, idOfLastUser);
    cout <<"Wczytano Plik z Wydatkami"<<endl;
};

void ExpenceManager::readExpencesFromFileOfLoggedUser()
{
    DataFile expencesFile;
    expences = expencesFile.loadXmlToVector(EXPENCE_FILE_NAME, ID_OF_LOGGED_USER, false, idOfLastUser);
    //cout <<"Wczytano Plik z Dochodami"<<endl;
};

void ExpenceManager::showUsersExpenceWithinDataRange(int rangeLeft, int rangeRight) //if the ranges are 0, method asks about the dates.
{
    DateAuxiliaryMethods dateOperator;
    int date1, date2;

    if ((rangeLeft==0) || (rangeRight==0))
    {
        cout<<"Data poczatkowa:"<<endl;
        date1 = dateInput();
        cout<<"Data koncowa:"<<endl;
        date2 = dateInput();
    }
    else
    {
        date1 = rangeLeft;
        date2 = rangeRight;
    };

    sortVectorWithFinancialDataAccordingToDate(expences);
    theLoopCoutsVectorOfFinancialDataWithinDates(expences,date1, date2);
    cout <<"--------------";
    cout <<endl<<"Suma Wydatkow:"<< fixed << setprecision(2)<<expencesInTotal(date1, date2)<<"zl."<<endl;
};

float ExpenceManager::expencesInTotal(int date1, int date2)
{
    return sumUpVectorWithFinancialDataWithinDataRange(expences, date1, date2);
};

void ExpenceManager::clearExpences()
{
    expences.clear();
};
