#include "UserManager.h"

void UserManager::setIdOfLoggedUser(int newIdOfLoggedUser)
{
    idOfLoggedUser = newIdOfLoggedUser;
};
int UserManager::getIdOfLoggedUser()
{
    return idOfLoggedUser;
};
void UserManager::addUser()
{
    User IndividualUserData;
    string lineOfData;

    system("cls");
    cout <<"Login:"<<endl;
    cin >> lineOfData;
    IndividualUserData.setLogin(lineOfData);
    cout <<"Haslo:"<<endl;
    cin >> lineOfData;
    IndividualUserData.setPassword(lineOfData);
    cout <<"Imie:"<<endl;
    cin >> lineOfData;
    IndividualUserData.setName(lineOfData);
    cout <<"Nazwisko:"<<endl;
    cin>>lineOfData;
    IndividualUserData.setSurname(lineOfData);

    users.push_back(IndividualUserData);
};

