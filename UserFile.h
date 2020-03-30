#ifndef USERFILE_H_INCLUDED
#define USERFILE_H_INCLUDED

#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"

using namespace std;

class UserFile
{
public:
    void saveXML(vector<User> users, string FileName);
};


#endif // USERFILE_H_INCLUDED
