#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>

#include "AuxiliaryMethods.h";
#include "FinanceManager.h";

using namespace std;

class Menu
{
    //FinanceManager financeManager;
public:
    char menuLoggedOut();
    char menuLoggedIn();
};


#endif // MENU_H_INCLUDED
