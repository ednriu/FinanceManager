#include <iostream>
#include "User.h"
#include "UserManager.h"
#include "DateAuxiliaryMethods.h"

using namespace std;

int main()
{
    DateAuxiliaryMethods test;

    cout <<"1:"<< test.verifyTheDate("2003-02-28")<<endl;
    cout <<"2:"<< test.verifyTheDate("2004-02-29")<<endl;
    cout <<"3:"<< test.verifyTheDate("2000-13-09")<<endl;
    cout <<"4:"<< test.verifyTheDate("2003-03-30")<<endl;
    cout <<"5:"<< test.verifyTheDate("2000-03-32")<<endl;
    cout <<"6:"<< test.verifyTheDate("2003-03-31")<<endl;



    UserManager userManager("Users.xml");
    userManager.registration();
    //userManager.logIn();

    return 0;
}
