#include "Menu.h"

char Menu::menuLoggedOut()
{
    AuxiliaryMethods auxiliaryMethods;
    system("cls");
    cout<<"+-------------------------+"<<endl;
    cout<<"|Zaloguj (z)              |"<<endl;
    cout<<"|Rejestracja (r)          |"<<endl;
    cout<<"|Zakoncz (k)              |"<<endl;
    cout<<"+-------------------------+"<<endl;
    return auxiliaryMethods.readKey();
};
char Menu::menuLoggedIn()
{
    AuxiliaryMethods auxiliaryMethods;
    system("cls");
    cout << "+--------------------------------------+"<<endl;
    cout << "|Dodaj przychod (p)                    |"<<endl;
    cout << "|Dodaj wydatek (w)                     |"<<endl;
    cout << "|Bilans z biezacego miesiaca (c)       |"<<endl;
    cout << "|Bilans z poprzedniego miesiaca (x)    |"<<endl;
    cout << "|Bilans z wybranego okresu (z)         |"<<endl;
    cout << "|Zmien haslo (h)                       |"<<endl;
    cout << "|Wyloguj sie (k)                       |"<<endl;
    cout << "+--------------------------------------+"<<endl;
    return auxiliaryMethods.readKey();
};
