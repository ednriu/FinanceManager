#include <iostream>
#include "User.h"
#include "UserManager.h"
#include "DateAuxiliaryMethods.h"

using namespace std;

int main()
{
    DateAuxiliaryMethods test;

    cout << test.convertDataIntegerToString(30032);
    cout <<endl;

    UserManager userManager("Users.xml");
    userManager.registration();
    //userManager.logIn();

    return 0;
}
