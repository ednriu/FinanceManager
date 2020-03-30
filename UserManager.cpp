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
    UserFile userFile;
    string lineOfData;

    system("cls");
    cout <<"Login:";
    cin >> lineOfData;
    IndividualUserData.setLogin(lineOfData);
    cout << endl <<"Haslo:";
    cin >> lineOfData;
    IndividualUserData.setPassword(lineOfData);
    cout <<endl<<"Imie:";
    cin >> lineOfData;
    IndividualUserData.setName(lineOfData);
    cout <<endl<<"Nazwisko:";
    cin>>lineOfData;
    IndividualUserData.setSurname(lineOfData);

    users.push_back(IndividualUserData);
    userFile.saveXML(users, USER_FILE_NAME);
};

void UserManager::readUsersFromFile()
{
    cout <<"Wczytuje Plik"<<endl;
};

