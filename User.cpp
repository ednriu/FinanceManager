#include "user.h"

    void User::setId(int newId)
    {
        id = newId;
    };
    void User::setLogin(string newLogin)
    {
        login = newLogin;
    };
    void User::setName(string newName)
    {
        name = newName;
    };
    void User::setSurname(string newSurname)
    {
        surname = newSurname;
    };
    int User::getId()
    {
        return id;
    };
    string User::getLogin()
    {
        return login;
    };
    string User::getName()
    {
        return name;
    };
    string User::getSurname()
    {
        return surname;
    };
