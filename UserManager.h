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
            cout <<"niepusty"<<endl;
            vector <User> :: iterator it = prev(users.end());
            cout << (*it).getId()<<endl;;
        }
    };
    void setIdOfLoggedUser(int newIdOfLoggedUser);
    int getIdOfLoggedUser();
    void addUser();
    void readUsersFromFile();
    void login();
};


#endif // USERMANAGER_H_INCLUDED
