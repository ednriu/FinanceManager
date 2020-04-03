#ifndef FINANCEMANAGER_H_INCLUDED
#define FINANCEMANAGER_H_INCLUDED

#include <iostream>

#include "UserManager.h"

using namespace std;

class FinanceManager
{
    UserManager userManager;
public:
    FinanceManager(string userFileName):userManager(userFileName){};
    void toRegisterUser();
    void toLogUserIn();
    bool isUserLoggedIn();

};


#endif // FINANCEMANAGER_H_INCLUDED
