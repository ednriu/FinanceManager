#include <iostream>
#include "User.h"
#include "UserManager.h"

using namespace std;

int main()
{
    UserManager userManager("Users.xml");
    //userManager.addUser();
    userManager.login();

    return 0;
}
