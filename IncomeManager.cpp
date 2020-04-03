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

    cin.ignore();
    cout<<"Kategoria:";
    getline(cin,category);
    return category;
};

void IncomeManager::getPLNfromInt(int moneyInt)
{
    float moneyFloat;
    moneyFloat = ((float)moneyInt/100);
    cout<<fixed;
    cout << setprecision(2)<<moneyFloat;
};

void IncomeManager::showUsersIncomeWithinDataRange()
{
    DateAuxiliaryMethods dateOperator;


    readIncomesFromFileOfOneUser(); //zmienic nazwe na ofLoggedUser

    int date1 = dateOperator.provideDataOfFirstDayMonthBefore();
    int date2 = dateOperator.provideDataofLastDayMonthBefore();

    sort(incomes.begin(), incomes.end(), [](FinancialData& lhs, FinancialData& rhs) {
      return lhs.getDate() < rhs.getDate();
   });

    for(vector <FinancialData> :: iterator it = incomes.begin(); it != incomes.end(); ++it)
        {
           cout << dateOperator.convertDataIntegerToString((*it).getDate());
           cout <<" -> ";
           cout << (*it).getCategory();
           cout<<" -> ";
           getPLNfromInt((*it).getMoneyAmmount());
           cout<<"zl."<<endl;
        }


    incomes.clear();
};
