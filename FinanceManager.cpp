#include "FinanceManager.h"


void FinanceManager::toRegisterUser()
{
    userManager.registration();
};

void FinanceManager::toLogUserIn()
{
    userManager.logIn();
};

bool FinanceManager::isUserLoggedIn()
{
    if(userManager.getIdOfLoggedUser()==0) return false;
    if(userManager.getIdOfLoggedUser()!=0) return true;
};

