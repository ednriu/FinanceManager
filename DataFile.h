#ifndef DATAFILE_H_INCLUDED
#define DATAFILE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

#include "Markup.h"
#include "FinancialData.h"

using namespace std;

class DataFile
{
public:
    void saveXmlFromVector(vector<FinancialData> &anyDate, string FileName);
    vector<FinancialData> loadXmlToVector(string FileName, int idOfLoggedUser, bool loadAllUsersData);
};


#endif // USERFILE_H_INCLUDED
