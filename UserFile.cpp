#include "userfile.h"

void UserFile::saveXML()
{
    CMarkup xml;
    xml.AddElem( "ORDER" );
    xml.IntoElem();
    xml.AddElem( "ITEM" );
    xml.IntoElem();
    xml.AddElem( "SN", "132487A-J" );
    xml.AddElem( "NAME", "crank casing" );
    xml.AddElem( "QTY", "1" );
    xml.Save( "F:\NaukaCPP\FinanceManager\Sample.xml" );
    cout << "koniec" <<endl;
};

