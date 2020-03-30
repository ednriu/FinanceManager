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
    const string USER_FILE_NAME;



public:
    UserManager(string userFileName):USER_FILE_NAME(userFileName)
    {
        readUsersFromFile();
    };
    void setIdOfLoggedUser(int newIdOfLoggedUser);
    int getIdOfLoggedUser();
    void addUser();
    void readUsersFromFile();
};


#endif // USERMANAGER_H_INCLUDED
