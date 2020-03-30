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

    //wypisz wszystkich uzytkownikow
    for(vector <User> :: iterator it = users.begin(); it != users.end(); ++it)
    {
        cout << (*it).getId()<<" "<< (*it).getName()<<" "<< (*it).getSurname()<<endl;
    }
    //koniec wypisz wszystkic uzytkownikow


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
    userFile.saveXmlFromVector(users, USER_FILE_NAME);
};

void UserManager::readUsersFromFile()
{
    UserFile userFile;

    users = userFile.loadXmlToVector(USER_FILE_NAME);
    cout <<"Wczytuje Plik"<<endl;
};

void UserManager::login()
{
    string lineOfData="";
    string correctPassword="";
    int correctId;
    bool loginExists = false;

    system("cls");
    cout <<"Login:";
    cin >> lineOfData;

    for(vector <User> :: iterator it = users.begin(); it != users.end(); ++it)
    {
        if ((*it).getLogin() == lineOfData)
        {
            correctPassword = (*it).getPassword();
            correctId = (*it).getId();
            cout <<"OK"<<endl;
            loginExists=true;
            break;
        }
    }

    if(loginExists)
    {
        lineOfData = "";
        int count_down = 3;
        while((lineOfData!=correctPassword) && (count_down>0))
        {
            cout<<endl<<"Haslo:";
            cin >> lineOfData;
            if (lineOfData==correctPassword)
            {
                cout <<"Zalogowales sie"<<endl;
                idOfLoggedUser = correctId;
                break;
            }
            count_down--;
        }

        if (count_down==0)
            cout<<"Przekroczona liczba prob."<<endl;
    }
    else if(!loginExists)
    {
        cout <<"Podales bledny Login"<<endl;
    }

};

