#include <iostream>
#include "User.h"
#include "UserManager.h"
#include "DateAuxiliaryMethods.h"

using namespace std;

int main()
{
    DateAuxiliaryMethods test;


    UserManager userManager("Users.xml");
    //userManager.registration();
    userManager.logIn();
    //userManager.passwordChange();

    return 0;
}
