#include <iostream>
#include "User.h"
#include "UserManager.h"
#include "DateAuxiliaryMethods.h"
#include "IncomeManager.h"

using namespace std;

int main()
{
    IncomeManager test;


    UserManager userManager("Users.xml");
    //userManager.registration();
    //userManager.logIn();
    //userManager.passwordChange();

    test.addIncome();


    return 0;
}
