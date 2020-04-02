#include "DataFile.h"

void DataFile::saveXmlFromVector(vector<FinancialData> &anyData, string FileName)
{
    CMarkup xml;

    xml.AddElem(FileName);
    xml.IntoElem();
    for(vector <FinancialData> :: iterator it = anyData.begin(); it != anyData.end(); ++it)
    {
        xml.AddElem("ITEM");
        xml.IntoElem();
        xml.AddElem("ID",to_string((*it).getId()));
        xml.AddElem( "USER_ID", (*it).getUserId());
        xml.AddElem( "CATEGORY", (*it).getCategory());
        xml.AddElem( "MONEY_AMMOUNT", (*it).getMoneyAmmount());
        xml.AddElem( "DATE", (*it).getDate());
        xml.OutOfElem();
    }
    xml.OutOfElem();
    xml.Save("E:\\NaukaCPP\\FinanceManager\\" + FileName);
};

vector<FinancialData> DataFile::loadXmlToVector(string FileName)
{
    CMarkup xml;
    FinancialData individualFinancialRecord;
    vector<FinancialData> anyData;

    xml.Load("E:\\NaukaCPP\\FinanceManager\\" + FileName);

    xml.ResetPos(); // top of document
    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER

    while ( xml.FindElem("ITEM") )
    {
        xml.IntoElem();

        xml.FindElem("ID");
        individualFinancialRecord.setId(atoi(MCD_2PCSZ(xml.GetData())));

        xml.FindElem( "USER_ID" );
        individualFinancialRecord.setUserId(atoi(MCD_2PCSZ(xml.GetData())));

        xml.FindElem( "CATEGORY" );
        individualFinancialRecord.setCategory(xml.GetData());

        xml.FindElem( "MONEY_AMMOUNT" );
        individualFinancialRecord.setMoneyAmmount(atoi(MCD_2PCSZ(xml.GetData())));

        xml.FindElem( "DATE" );
        individualFinancialRecord.setDate(atoi(MCD_2PCSZ(xml.GetData())));

        xml.OutOfElem();
        anyData.push_back(individualFinancialRecord);
    }
    return anyData;
};


