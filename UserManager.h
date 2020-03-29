#ifndef USERMANAGER_H_INCLUDED
#define USERMANAGER_H_INCLUDED
#include <vector>

#include "user.h"

class UserManager
{
    vector<User> users;
    int idOfLoggedUser;

public:
    void setIdOfLoggedUser(int newIdOfLoggedUser);
    int getIdOfLoggedUser();
};


#endif // USERMANAGER_H_INCLUDED
