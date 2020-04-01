#ifndef DATEAUXILIARYMETHODS_H_INCLUDED
#define DATEAUXILIARYMETHODS_H_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include <time.h>

using namespace std;

class DateAuxiliaryMethods
{
    bool isLeapYear(int provideYear);
    string addZeroToDateDigit(string digits);
    int getDaysInMonth(int monthNumber, bool isYearLeap);
    int verifyTheDate(string dateToBeChecked);

public:
    int convertStringToDataInteger(string provideDate);
    string convertDataIntegerToString(int provideDateInteger);
    int provideDataOfFirstDayThisMonth();
    int provideDataOfFirstDayMonthBefore();
    int provideDataofLastDayThisMonth();
    int provideDataofLastDayMonthBefore();
    int provideDataOfToday();
};


#endif // DATEAUXILIARYMETHODS_H_INCLUDED
