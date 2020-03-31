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
    int idOfLastUser;
    const string USER_FILE_NAME;

public:
    UserManager(string userFileName):USER_FILE_NAME(userFileName)
    {
        idOfLastUser = 0;
        idOfLoggedUser = 0;
        readUsersFromFile();
        if (!users.empty())
        {
            vector <User> :: iterator it = prev(users.end());
            idOfLastUser = (*it).getId();
        }
    };
    void setIdOfLoggedUser(int newIdOfLoggedUser);
    int getIdOfLoggedUser();
    void registration();
    void readUsersFromFile();
    void logIn();
    void logOut();
};


#endif // USERMANAGER_H_INCLUDED
