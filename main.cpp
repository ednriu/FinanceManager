#include <iostream>
#include "User.h"
#include "UserManager.h"
#include "DateAuxiliaryMethods.h"
#include "IncomeManager.h"
#include "FinanceManager.h"
#include "Menu.h"

using namespace std;

int main()
{
    int testowanie; //ta zmienna jest tylko do sprawdzenia funkcjonalnosci gita podczas scalania
    setlocale(LC_ALL,"");
    Menu menu;
    FinanceManager financeManager("users.xml");
    while(1)
    {
        if (financeManager.isUserLoggedIn()==false)
        {
            switch(menu.menuLoggedOut())
            {
            case 'z' :
                financeManager.toLogUserIn();
                break;
            case 'r' :
                financeManager.toRegisterUser();
                break;
            case 'k' :
                return 0;
            }
        }
        if (financeManager.isUserLoggedIn()==true)
            switch(menu.menuLoggedIn())
            {
            case 'p' :
                financeManager.toAddIncome();
                break;
            case 'w' :
                financeManager.toAddExpence();
                break;
            case 'h' :
                financeManager.toChangePassword();
                break;
            case 'k' :
                financeManager.toLogUserOut();
                break;
            case 'c' :
                financeManager.showBalanceForThatMonth();
                break;
            case 'x' :
                financeManager.showBalanceForLastMonth();
                break;
            case 'z' :
                financeManager.showBalanceBetweenTwoDates();
                break;
            }
    }

    return 0;
}

/*int test_main()
{
    ExpenceManager test(4);

    UserManager userManager("Users.xml");
    test.addExpence();
    system("pause");



    return 0;
}*/
