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
                //financeManager.toRegisterUser();
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

int test_main()
{
    IncomeManager test(2);
    DateAuxiliaryMethods date1;
    DateAuxiliaryMethods date2;


    UserManager userManager("Users.xml");
    test.showUsersIncomeWithinDataRange(date1.provideDataOfFirstDayMonthBefore(), date2.provideDataofLastDayThisMonth());
    system("pause");



    return 0;
}
