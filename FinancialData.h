#ifndef FINANCIALDATA_H_INCLUDED
#define FINANCIALDATA_H_INCLUDED

#include <iostream>

using namespace std;

class FinancialData
{
    int id;
    int userId;
    string category;
    int moneyAmmount;
    int date;
public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setCategory(string newCategory);
    void setMoneyAmmount(int newMoneyAmmount);
    void setDate(int newDate);
    int getId();
    int getUserId();
    string getCategory();
    int getMoneyAmmount();
    int getDate();
};


#endif // FINANCIALDATA_H_INCLUDED
