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
