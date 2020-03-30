#include "userfile.h"

void UserFile::saveXML(vector<User> users, string FileName)
{
    CMarkup xml;
    xml.AddElem( "USERS" );
    xml.IntoElem();
    xml.AddElem( "1" );
    xml.IntoElem();

    for(vector <User> :: iterator it = users.begin(); it != users.end(); ++it)
    {
        xml.AddElem( "LOGIN", (*it).getLogin());
        xml.AddElem( "PASSWORD", (*it).getPassword());
        xml.AddElem( "NAME", (*it).getName());
        xml.AddElem( "SURNAME", (*it).getSurname());
    }

    xml.Save( "E:\\NaukaCPP\\FinanceManager\\" + FileName);
    cout << "koniec" <<endl;
};


