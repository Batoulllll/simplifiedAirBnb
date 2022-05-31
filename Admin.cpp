#include "Admin.h"
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

Admin:: Admin(string n, string m, string p)
{
    name = n;
    mail = m;
    pass = p;
}

Admin:: Admin()
{
    name = "";
    mail = "";
    pass = "";
}
    