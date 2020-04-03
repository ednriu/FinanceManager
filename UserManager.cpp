#include "UserManager.h"


void UserManager::setIdOfLoggedUser(int newIdOfLoggedUser)
{
    idOfLoggedUser = newIdOfLoggedUser;
};
int UserManager::getIdOfLoggedUser()
{
    return idOfLoggedUser;
};
void UserManager::registration()
{
    User individualUserData;
    UserFile userFile;
    AuxiliaryMethods auxiliaryMethods;
    string lineOfData;

    individualUserData.setId(idOfLastUser+1);
    system("cls");
    auxiliaryMethods.printHeader("Rejestracja Uzytkownika");
    cout <<"Login:";
    cin >> lineOfData;
    while (doesLoginExist(lineOfData))
    {
        cout << "Podany login istnieje. Podaj jeszcze raz."<<endl;
        cout <<"Login:";
        cin >> lineOfData;
    }
    individualUserData.setLogin(lineOfData);
    cout <<"Haslo:";
    cin >> lineOfData;
    individualUserData.setPassword(lineOfData);
    cout <<"Imie:";
    cin >> lineOfData;
    individualUserData.setName(lineOfData);
    cout <<"Nazwisko:";
    cin>>lineOfData;
    individualUserData.setSurname(lineOfData);
    users.push_back(individualUserData);
    idOfLastUser = idOfLastUser+1;
    userFile.saveXmlFromVector(users, USER_FILE_NAME);
};

void UserManager::readUsersFromFile()
{
    UserFile userFile;
    users = userFile.loadXmlToVector(USER_FILE_NAME);
    cout <<"Wczytano Plik z Uzytkownikami"<<endl;
};

void UserManager::logIn()
{
    string lineOfData="";
    string correctPassword="";
    int correctId;
    bool loginExists = false;
    AuxiliaryMethods auxiliaryMethods;

    system("cls");
    auxiliaryMethods.printHeader("Logowanie");
    cout <<"Login:";
    cin >> lineOfData;

    for(vector <User> :: iterator it = users.begin(); it != users.end(); ++it)
    {
        if ((*it).getLogin() == lineOfData)
        {
            correctPassword = (*it).getPassword();
            correctId = (*it).getId();
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
            cout<<"Haslo:";
            cin >> lineOfData;
            if (lineOfData==correctPassword)
            {
                cout <<"Zalogowales sie"<<endl;
                idOfLoggedUser = correctId;
                system("pause");
                break;
            };

            if (lineOfData!=correctPassword)
            {
                system("cls");
                cout << "Haslo jest niepoprawne. Sprobuj jeszcze raz."<<endl;
            };
            count_down--;
        }

        if (count_down==0)
            cout<<"Przekroczona liczba prob."<<endl;
    }
    else if(!loginExists)
    {
        cout <<"Podales bledny Login. Sprobuj jeszcze raz."<<endl;
        system("pause");
    }

};

void UserManager::logOut()
{
    idOfLoggedUser = 0;
};

void UserManager::passwordChange()
{
    string newPassword;
    UserFile userFile;

    system("cls");
    if (idOfLoggedUser!=0)
    {
        cout << "Nowe haslo:";
        cin >> newPassword;

        for(vector <User> :: iterator it = users.begin(); it != users.end(); ++it)
        {
            if ((*it).getId() == idOfLoggedUser)
            {
                (*it).setPassword(newPassword);
                cout <<"Haslo zostalo zmienione"<<endl;
                userFile.saveXmlFromVector(users, USER_FILE_NAME);
                break;
            }
        }
    }
    else
    if (idOfLoggedUser==0)
    {
        system("cls");
        cout << "Jestes niezalogowany"<<endl;
        system("Pause");
    }

};

bool UserManager::doesLoginExist(string loginToBeChecked)
{
    for(vector <User> :: iterator it = users.begin(); it != users.end(); ++it)
    {
        if ((*it).getLogin() == loginToBeChecked)
        {
            cout <<"Login Istnieje:"<<endl;
            return true;
        }
    }
return false;
};

