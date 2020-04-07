#include "FinancialData.h"


void FinancialData::setId(int newId)
{
    id = newId;
};
void FinancialData::setUserId(int newUserId)
{
    userId = newUserId;
};
void FinancialData::setCategory(string newCategory)
{
    category = newCategory;
};
void FinancialData::setMoneyAmmount(float newMoneyAmmount)
{
    moneyAmmount = newMoneyAmmount;
};
void FinancialData::setDate(int newDate)
{
    date = newDate;
};
int FinancialData::getId()
{
    return id;
};
int FinancialData::getUserId()
{
    return userId;
};
string FinancialData::getCategory()
{
    return category;
};
float FinancialData::getMoneyAmmount()
{
    return moneyAmmount;
};
int FinancialData::getDate()
{
    return date;
};
