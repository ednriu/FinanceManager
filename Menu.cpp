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
    cout << "Dodaj przychód"<<endl;
    cout << "Dodaj wydatek"<<endl;
    cout << "Bilans z bie¿¹cego miesi¹ca"<<endl;
    cout << "Bilans z poprzedniego miesi¹ca"<<endl;
    cout << "Bilans z wybranego okresu"<<endl;
    cout << "Zmien has³o"<<endl;
    cout << "Wyloguj siê"<<endl;
    return auxiliaryMethods.readKey();
};
