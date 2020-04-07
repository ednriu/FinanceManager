#ifndef FINANCIALDATA_H_INCLUDED
#define FINANCIALDATA_H_INCLUDED

#include <iostream>
#include <iomanip>

using namespace std;

class FinancialData
{
    int id;
    int userId;
    string category;
    float moneyAmmount;
    int date;
public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setCategory(string newCategory);
    void setMoneyAmmount(float newMoneyAmmount);
    void setDate(int newDate);
    int getId();
    int getUserId();
    string getCategory();
    float getMoneyAmmount();
    int getDate();
};


#endif // FINANCIALDATA_H_INCLUDED
