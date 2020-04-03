#include "Menu.h"

char Menu::menuLoggedOut()
{
    AuxiliaryMethods auxiliaryMethods;
    system("cls");
    cout<<"Zaloguj (z)"<<endl;
    cout<<"Rejestracja (r)"<<endl;
    cout<<"Zakoncz (k)"<<endl;
    return auxiliaryMethods.readKey();
};
char Menu::menuLoggedIn()
{
    AuxiliaryMethods auxiliaryMethods;
    system("cls");
    cout << "Dodaj przychód (p)"<<endl;
    cout << "Dodaj wydatek (w)"<<endl;
    cout << "Bilans z bieżącego miesiąca (c)"<<endl;
    cout << "Bilans z poprzedniego miesiąca (x)"<<endl;
    cout << "Bilans z wybranego okresu (z)"<<endl;
    cout << "Zmien haslo (h)"<<endl;
    cout << "Wyloguj siê (k)"<<endl;
    return auxiliaryMethods.readKey();
};
