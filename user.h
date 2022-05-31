#ifndef USER_H
#define USER_H
#include<string>
using namespace std;
class user
{
public:
    string regemail, regpass, PhoneNum, Fname, Lname, Birthdate;

    user();
    user(string regn, string regp, string Pn, string Fn, string Ln, string Bd);
    bool login();
    void  registertion();

};

#endif // USER_H

