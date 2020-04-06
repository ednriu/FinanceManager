#include "ExpenceManager.h"


void ExpenceManager::addExpence()
{
    FinancialData pieceOfData;
    DataFile fileWithExpences;
    DateAuxiliaryMethods dateOperator;
    string dataReader;

    readAllExpencesFromFile(EXPENCE_FILE_NAME);

    system("cls");
    int dateTemp = IncomeManager::dateInput();
    pieceOfData.setDate(dateTemp);
    pieceOfData.setId(1234);
    pieceOfData.setUserId(ID_OF_LOGGED_USER);
    pieceOfData.setCategory(categoryInput());
    pieceOfData.setMoneyAmmount(moneyInput());

    expences.push_back(pieceOfData);

    fileWithExpences.saveXmlFromVector(expences, EXPENCE_FILE_NAME);
    expences.clear();
}

void ExpenceManager::readAllExpencesFromFile(string fileName)
{
    DataFile expencesFile;
    expences = expencesFile.loadXmlToVector(fileName, ID_OF_LOGGED_USER, true);
    cout <<"Wczytano Plik z Wydatkami"<<endl;
};

void ExpenceManager::readExpencesFromFileOfLoggedUser(string fileName)
{
    DataFile expencesFile;
    expences = expencesFile.loadXmlToVector(fileName, ID_OF_LOGGED_USER, false);
    //cout <<"Wczytano Plik z Dochodami"<<endl;
};

void ExpenceManager::showUsersExpenceWithinDataRange(int rangeLeft, int rangeRight) //if the ranges are 0, method asks about the dates.
{
    DateAuxiliaryMethods dateOperator;
    readExpencesFromFileOfLoggedUser(EXPENCE_FILE_NAME);
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
    cout <<endl<<"Suma Wplywow:"<< fixed << setprecision(2)<<sumUpVectorWithFinancialDataWithinDataRange(expences, date1, date2)<<"zl."<<endl;
    expences.clear();
};
