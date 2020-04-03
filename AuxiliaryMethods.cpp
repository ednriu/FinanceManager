#include "AuxiliaryMethods.h"

char AuxiliaryMethods::readKey()
{
        char key;
        key = _getch();
        return key;
};

char AuxiliaryMethods::printHeader(string textToBePrinted)
{
    //system("Color 3B");
    int counter;
    string textToBeReturned="";

    for (counter=0; counter<textToBePrinted.length(); counter++)
    {
        textToBeReturned.push_back(toupper(textToBePrinted[counter]));
    };
    cout<<textToBeReturned<<endl;
    for (counter=0; counter<textToBePrinted.length(); counter++)
    {
        cout<<"+";
    };
    cout <<endl;
};
