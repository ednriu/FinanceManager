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

    bool doesLoginExist(string loginToBeChecked);

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
    void passwordChange();
};


#endif // USERMANAGER_H_INCLUDED
