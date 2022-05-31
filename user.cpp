#include "user.h"
#include<string.h>
#include<iostream>
#include<istream>
#include<ostream>
#include<fstream>
#include"MyQueue.h"

using namespace std;

user::user(string regn, string regp, string Pn, string Fn, string Ln, string Bd)
{
    regemail = regn;
    regpass = regp;
    PhoneNum = Pn;
    Fname = Fn;
    Lname = Ln;
    Birthdate = Bd;


}

user::user()
{
    regemail = "";
    regpass = "";
    PhoneNum = "";
    Fname = "";
    Lname = "";
    Birthdate = "";

}

bool user::login() {

    string username, password, un, p;
    cout << "Type your e-mail: ";
    cin >> username;
    cout << "Type your password: ";
    cin >> password;

    ifstream input("D:\\trail\\file\\usersdata.txt");
    getline(input, un);
    getline(input, p);

    if (un == username && p == password) {
        return true;

    }
    else {
        return false;

    }
}

void user::registertion() {

    string remail, rpass, firstName, lastName, bdatee;
    int pnum;
    cout << "Type your e-mail: " << endl;
    cin >> remail;
    cout << "Create a password: " << endl;
    cin >> rpass;
    cout << "Enter phone number : ";
    cin >> pnum;
    cout << "First name: ";
    cin >> firstName;
    cout << "Last name: ";
    cin >> lastName;
    cout << "Enter your birth date: ";
    cin >> bdatee;
   
    ofstream reg("D:\\trail\\file\\usersdata.txt", ios::app);
    reg << remail << endl << rpass << endl << pnum << endl << firstName << endl << lastName << endl << bdatee << endl;

    reg.close();



}
