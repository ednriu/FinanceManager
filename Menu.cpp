#include "Menu.h"

char Menu::menuLoggedOut()
{
    AuxiliaryMethods auxiliaryMethods;
    cout<<"Zaloguj (z)"<<endl;
    cout<<"Rejestracja (r)"<<endl;
    cout<<"Zakoncz (k)"<<endl;
    return auxiliaryMethods.readKey();
};
char Menu::menuLoggedIn()
{
    AuxiliaryMethods auxiliaryMethods;
    cout << "Dodaj przych�d"<<endl;
    cout << "Dodaj wydatek"<<endl;
    cout << "Bilans z bie��cego miesi�ca"<<endl;
    cout << "Bilans z poprzedniego miesi�ca"<<endl;
    cout << "Bilans z wybranego okresu"<<endl;
    cout << "Zmien has�o"<<endl;
    cout << "Wyloguj si�"<<endl;
    return auxiliaryMethods.readKey();
};
