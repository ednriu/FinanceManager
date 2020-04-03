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
                //financeManager.toRegisterUser();
                break;
            case 'h' :
                financeManager.toChangePassword();
                break;
            case 'k' :
                financeManager.toLogUserOut();
                break;
            }
    }

    return 0;
}

/*int _main()
{
    IncomeManager test;


    UserManager userManager("Users.xml");
    //userManager.registration();
    //userManager.logIn();
    //userManager.passwordChange();
    //test.showUsersIncomeWithinDataRange();
    system("pause");
    test.addIncome();


    return 0;
}*/
