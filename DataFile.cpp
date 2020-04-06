#include "DataFile.h"


void DataFile::saveXmlFromVector(vector<FinancialData> &anyData, string FileName)
{
    CMarkup xml;
    DateAuxiliaryMethods dateAuxiliaryMethods;

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
        xml.AddElem( "DATE", dateAuxiliaryMethods.convertDataIntegerToString((*it).getDate()));
        xml.OutOfElem();
    }
    xml.OutOfElem();
    xml.Save(FileName+".xml");
    //"E:\\NaukaCPP\\FinanceManager\\" +
};

vector<FinancialData> DataFile::loadXmlToVector(string FileName, int idOfLoggedUser, bool loadAllUsersData)
{
    CMarkup xml;
    DateAuxiliaryMethods dateAuxiliaryMethods;
    FinancialData individualFinancialRecord;
    vector<FinancialData> anyData;

    xml.Load(FileName +".xml");
    //"E:\\NaukaCPP\\FinanceManager\\" +

    xml.ResetPos(); // top of document
    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER

    while ( xml.FindElem("ITEM") )
    {
        xml.IntoElem();

        if (loadAllUsersData==false)
        {
            xml.FindElem( "USER_ID" );
            while (atoi(MCD_2PCSZ(xml.GetData()))==idOfLoggedUser)
            {
                xml.FindElem("ID");
                individualFinancialRecord.setId(atoi(MCD_2PCSZ(xml.GetData())));

                xml.FindElem( "USER_ID" );
                individualFinancialRecord.setUserId(atoi(MCD_2PCSZ(xml.GetData())));

                xml.FindElem( "CATEGORY" );
                individualFinancialRecord.setCategory(xml.GetData());

                xml.FindElem( "MONEY_AMMOUNT" );
                individualFinancialRecord.setMoneyAmmount(atoi(MCD_2PCSZ(xml.GetData())));

                xml.FindElem( "DATE" );
                individualFinancialRecord.setDate(dateAuxiliaryMethods.convertStringToDataInteger(xml.GetData()));

                anyData.push_back(individualFinancialRecord);
            };
        };

        if (loadAllUsersData==true)
        {
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

            anyData.push_back(individualFinancialRecord);
        }



        xml.OutOfElem();

    }
    return anyData;
};


