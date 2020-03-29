#include "UserManager.h"

void UserManager::setIdOfLoggedUser(int newIdOfLoggedUser)
{
    idOfLoggedUser = newIdOfLoggedUser;
};
int UserManager::getIdOfLoggedUser()
{
    return idOfLoggedUser;
};
