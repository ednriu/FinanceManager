#include "IncomeManager.h"


void IncomeManager::readIncomesFromFileOfOneUser()
{
    DataFile incomesFile;
    incomes = incomesFile.loadXmlToVector(INCOME_FILE_NAME, ID_OF_LOGGED_USER, false);
    cout <<"Wczytano Plik z Dochodami"<<endl;
};

void IncomeManager::readAllIncomesFromFile()
{
    DataFile incomesFile;
    incomes = incomesFile.loadXmlToVector(INCOME_FILE_NAME, ID_OF_LOGGED_USER, true);
    cout <<"Wczytano Plik z Dochodami"<<endl;
};

void IncomeManager::addIncome()
{
    FinancialData pieceOfData;
    DataFile fileWithIncomes;
    DateAuxiliaryMethods dateOperator;
    string dataReader;

    readAllIncomesFromFile();

    system("cls");
    //dateInput();
    pieceOfData.setDate(dateInput());
    pieceOfData.setId(1234);
    pieceOfData.setUserId(ID_OF_LOGGED_USER);
    pieceOfData.setCategory(categoryInput());
    pieceOfData.setMoneyAmmount(moneyInput());

    incomes.push_back(pieceOfData);

    fileWithIncomes.saveXmlFromVector(incomes, INCOME_FILE_NAME);
    incomes.clear();
}

int IncomeManager::dateInput()
{
    AuxiliaryMethods auxiliaryMethods;
    DateAuxiliaryMethods dateOperator;
    string dateReader;

    cout <<"Dzien Dzisiejszy (d)"<<endl;
    cout<< "Inna Data (i)"<<endl;

    switch(auxiliaryMethods.readKey())
    {
    case 'd' :
        return dateOperator.provideDataOfToday();
        break;       // and exits the switch
    case 'i' :
        cout << "Data (YYYY-MM-DD):";
        cin >> dateReader;
        while (dateOperator.convertStringToDataInteger(dateReader)==0)
        {
            cout << "Podano zly format daty."<<endl;
            cout << "Data (YYYY-MM-DD):";
            cin >> dateReader;
        }
        return dateOperator.convertStringToDataInteger(dateReader);
        break;
    }
};

int IncomeManager::moneyInput()
{
    float ammount;
    int ammountMultiplied;

    cout<<"Kwota:";
    cin>>ammount;
    ammountMultiplied = ammount*100;
    return ammountMultiplied;
};

string IncomeManager::categoryInput()
{
    string category;

    cout<<"Kategoria:";
    getline(cin,category);
    return category;
};
