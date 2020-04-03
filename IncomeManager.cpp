#include "IncomeManager.h"


void IncomeManager::readIncomesFromFileOfLoggedUser()
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
    int dateTemp = dateInput();
    pieceOfData.setDate(dateTemp);
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

    cout <<"Dzien Dzisiejszy (d)"<<", ";
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

    cin.ignore();
    cout<<"Kategoria:";
    getline(cin,category);
    return category;
};

float IncomeManager::getPLNfromInt(int moneyInt)
{
    float moneyFloat;
    moneyFloat = ((float)moneyInt/100);
    return moneyFloat;
};
void IncomeManager::sortIncomesAccordingToDate()
{
    sort(incomes.begin(), incomes.end(), [](FinancialData& lhs, FinancialData& rhs) { //neecs attention: check why does not work with the Const
      return lhs.getDate() < rhs.getDate();
   });
};
void IncomeManager::showUsersIncomeWithinDataRange()
{
    DateAuxiliaryMethods dateOperator;
    readIncomesFromFileOfLoggedUser();

    int date1 = dateInput();
    int date2 = dateInput();

    sortIncomesAccordingToDate();

    for(vector <FinancialData> :: iterator it = incomes.begin(); it != incomes.end(); ++it)
        {
           if (((*it).getDate()>=date1)&&((*it).getDate()<=date2))
           {
                cout << dateOperator.convertDataIntegerToString((*it).getDate());
                cout <<" -> ";
                cout << (*it).getCategory();
                cout<<" -> ";
                cout << getPLNfromInt((*it).getMoneyAmmount());
                cout<<"zl."<<endl;
           }
        }
    cout << fixed << setprecision(2)<<sumUpUserIncomesWithinDataRange(date1, date2)<<endl;
    incomes.clear();
};

float IncomeManager::sumUpUserIncomesWithinDataRange(int date1, int date2)
{
    float sumToBeReturned=0;;
    DateAuxiliaryMethods dateOperator;

    for(vector <FinancialData> :: iterator it = incomes.begin(); it != incomes.end(); ++it)
        {
            if (((*it).getDate()>=date1)&&((*it).getDate()<=date2)) sumToBeReturned = sumToBeReturned+getPLNfromInt((*it).getMoneyAmmount());
        };

    return sumToBeReturned;
};
