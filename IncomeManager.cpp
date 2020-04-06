#include "IncomeManager.h"


void IncomeManager::readIncomesFromFileOfLoggedUser()
{
    DataFile incomesFile;
    incomes = incomesFile.loadXmlToVector(INCOME_FILE_NAME, ID_OF_LOGGED_USER, false);
    //cout <<"Wczytano Plik z Dochodami"<<endl;
};

void IncomeManager::readAllIncomesFromFile()
{
    DataFile incomesFile;
    incomes = incomesFile.loadXmlToVector(INCOME_FILE_NAME, ID_OF_LOGGED_USER, true);
    //cout <<"Wczytano Plik z Dochodami"<<endl;
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
    pieceOfData.setId(0);
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
    string ammount;
    int ammountMultiplied;

    cout<<"Kwota:";
    cin>>ammount;
    ammountMultiplied = (float)replaceCommaWithDot(ammount)*(float)100;
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
void IncomeManager::sortVectorWithFinancialDataAccordingToDate(vector<FinancialData> &vectorToBeSorted)
{
    sort(vectorToBeSorted.begin(), vectorToBeSorted.end(), [](FinancialData& lhs, FinancialData& rhs) { //neecs attention: check why does not work with the Const
      return lhs.getDate() < rhs.getDate();
   });
};
void IncomeManager::showUsersIncomeWithinDataRange(int rangeLeft, int rangeRight) //if the ranges are 0, method asks about the dates.
{
    DateAuxiliaryMethods dateOperator;
    //readIncomesFromFileOfLoggedUser(INCOME_FILE_NAME);
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

    sortVectorWithFinancialDataAccordingToDate(incomes);
    theLoopCoutsVectorOfFinancialDataWithinDates(incomes,date1, date2);
    cout <<endl<<"Suma Wplywow:"<< fixed << setprecision(2)<<incomesInTotal(date1, date2)<<"zl."<<endl;
    //incomes.clear();
};

float IncomeManager::sumUpVectorWithFinancialDataWithinDataRange(vector<FinancialData> &vectorToBeSummed, int date1, int date2)
{
    float sumToBeReturned=0;;
    DateAuxiliaryMethods dateOperator;

    for(vector <FinancialData> :: iterator it = vectorToBeSummed.begin(); it != vectorToBeSummed.end(); ++it)
        {
            if (((*it).getDate()>=date1)&&((*it).getDate()<=date2)) sumToBeReturned = sumToBeReturned+getPLNfromInt((*it).getMoneyAmmount());
        };

    return sumToBeReturned;
};
void IncomeManager::theLoopCoutsVectorOfFinancialDataWithinDates(vector<FinancialData> &vectorToBeCouted, int date1, int date2)
{
    DateAuxiliaryMethods dateOperator;

    for(vector <FinancialData> :: iterator it = vectorToBeCouted.begin(); it != vectorToBeCouted.end(); ++it)
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
}

float IncomeManager::replaceCommaWithDot(string text)
{
    int i;
    float valueToBeReturned;
    int len = text.length();
    for (i = 0; i < len; i++)
    {
        if (text[i] == ',')
        {
            text[i] = '.';
            i = len; // or `break;`
        }
    }
    valueToBeReturned = strtof((text).c_str(),0);
    return valueToBeReturned;
};

float IncomeManager::incomesInTotal(int date1, int date2)
{
return sumUpVectorWithFinancialDataWithinDataRange(incomes, date1, date2);
};

void IncomeManager::clearIncomes()
{
    incomes.clear();
};
