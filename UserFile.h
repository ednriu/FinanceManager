#ifndef USERFILE_H_INCLUDED
#define USERFILE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

#include "Markup.h"
#include "User.h"

using namespace std;

class UserFile
{
public:
    void saveXmlFromVector(vector<User> users, string FileName);
    vector<User> loadXmlToVector(string FileName);
};


#endif // USERFILE_H_INCLUDED
