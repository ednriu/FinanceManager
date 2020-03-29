#ifndef USERMANAGER_H_INCLUDED
#define USERMANAGER_H_INCLUDED
#include <vector>
#include <iostream>

#include "user.h"
#include "UserFile.h"

using namespace std;

class UserManager
{
    vector<User> users;
    int idOfLoggedUser;



public:
    void setIdOfLoggedUser(int newIdOfLoggedUser);
    int getIdOfLoggedUser();
    void addUser();
};


#endif // USERMANAGER_H_INCLUDED
