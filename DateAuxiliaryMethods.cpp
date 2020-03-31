#include "DateAuxiliaryMethods.h"

bool DateAuxiliaryMethods::isLeapYear(int provideYear)
{
    if (provideYear%400==0) return true;
    if ((provideYear%100!=0)&(provideYear%4==0)) return true;
    return false;
}

int DateAuxiliaryMethods::convertStringToDataInteger(string provideDate)
{
    string year, month, day;
    int valueToBeReturned = 0;
    map < int, int > mapa;

    year = provideDate.substr(0,4);
    month = provideDate.substr(5,2);
    day = provideDate.substr(8,2);

    mapa[1]=31;
    if (isLeapYear(stoi(year))) mapa[2]=mapa[1]+29;
    if (!isLeapYear(stoi(year))) mapa[2]=mapa[1]+28;
    mapa[3]=mapa[2]+31;
    mapa[4]=mapa[3]+30;
    mapa[5]=mapa[4]+31;
    mapa[6]=mapa[5]+30;
    mapa[7]=mapa[6]+31;
    mapa[8]=mapa[7]+31;
    mapa[9]=mapa[8]+30;
    mapa[10]=mapa[9]+31;
    mapa[11]=mapa[10]+30;


    valueToBeReturned = ((stoi(year)-1990)*1000)+mapa[stoi(month)-1]+stoi(day);
    return valueToBeReturned;
}

string DateAuxiliaryMethods::convertDataIntegerToString(int provideDateInteger)
{
    string year, month, day;
    string dateToBeReturned;
    map < int, int > mapa;

    year = to_string((provideDateInteger / 1000)+1990);

    mapa[0]=0;
    mapa[1]=31;
    if (isLeapYear(stoi(year))) mapa[2]=mapa[1]+29;
    if (!isLeapYear(stoi(year))) mapa[2]=mapa[1]+28;
    mapa[3]=mapa[2]+31;
    mapa[4]=mapa[3]+30;
    mapa[5]=mapa[4]+31;
    mapa[6]=mapa[5]+30;
    mapa[7]=mapa[6]+31;
    mapa[8]=mapa[7]+31;
    mapa[9]=mapa[8]+30;
    mapa[10]=mapa[9]+31;
    mapa[11]=mapa[10]+30;
    mapa[12]=mapa[11]+31;

    int count_up = 1;

    while(mapa[count_up]<(provideDateInteger % 1000))
          {
              count_up++;
          }
    month = addZeroToDateDigit(to_string(count_up));

    day = addZeroToDateDigit(to_string((provideDateInteger % 1000)-mapa[count_up-1]));

    dateToBeReturned = year + "-"  + month + "-" + day;
    return dateToBeReturned;
}

string DateAuxiliaryMethods::addZeroToDateDigit(string digits)
{
    if (digits.length()==1) digits = '0'+digits;
    if (digits.length()==2) return digits;
};

int DateAuxiliaryMethods::provideDataOfFirstDayThisMonth()
{
    int dateToBeReturned;
    string dateInString;
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900; // Year is # years since 1900

    dateInString = to_string(year)+"-"+to_string(month)+"-01";
    dateToBeReturned = convertStringToDataInteger(dateInString);
    return dateToBeReturned;
};

int DateAuxiliaryMethods::provideDataOfFirstDayMonthBefore()
{
    int dateToBeReturned;
    string dateInString;
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int month = aTime->tm_mon; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept. In that case it is needed the month before.
    int year = aTime->tm_year + 1900; // Year is # years since 1900

    if (month==12) year = year--; //If previous month is december, the number of year must be decreased

    dateInString = to_string(year)+"-"+to_string(month)+"-01";
    dateToBeReturned = convertStringToDataInteger(dateInString);
    return dateToBeReturned;
};

