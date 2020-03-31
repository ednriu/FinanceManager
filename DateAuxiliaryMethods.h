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


public:
    int convertStringToDataInteger(string provideDate);
    string convertDataIntegerToString(int provideDateInteger);
    int provideDataOfFirstDayThisMonth();
    int provideDataOfFirstDayMonthBefore();

};


#endif // DATEAUXILIARYMETHODS_H_INCLUDED
