#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<string.h>
#include<ostream>
#include<istream>
#include "MyQueue.cpp"
#include "user.h"
#include "Admin.h"
#include <queue>
using namespace std;




class places
{
public:
    string barcode; //unique for editing
    string startdate;
    string enddate;
    string stayduration;
    string city;
    string price;

    places(string b, string sd, string ed, string stduration, string cc, string pri)
    {
        barcode = b;
        startdate = sd;
        enddate = ed;
        stayduration = stduration;
        city = cc;
        price = pri;
    }
    places()
    {
        barcode = "";
        startdate = "";
        enddate = "";
        stayduration = "";
        city = "";
        price = "";
    }

};


vector<Admin> admin; //arrays of Admin
vector<places> place;//array of places

user users;

//parse function  for admin
Admin parr(string adn) {
    Admin ad;
    //adn =name, mail, phone as jack,jack.gmail.com,010364187278
    string data[3];
    string text = "";
    int j = 0;
    for (int i = 0; i < adn.length(); i++) {
        if (adn[i] == ',') {
            data[j] = text;
            text = "";
            j++;
            continue;
        }
        text = text + adn[i];

    }
    data[j] = text;
    ad.name = data[0];
    ad.mail = data[1];
    ad.pass = data[2];
    return ad;
}

//parse function for places
places par(string pl) {
    places p;
    string data[6];
    string text = "";
    int j = 0;
    for (int i = 0; i < pl.length(); i++) {
        if (pl[i] == ',') {
            data[j] = text;
            text = "";
            j++;
            continue;
        }
        text = text + pl[i];

    }
    data[j] = text;
    p.barcode = data[0];
    p.startdate = data[1];
    p.enddate = data[2];
    p.stayduration = data[3];
    p.city = data[4];
    p.price = data[5];
    return p;
}

//search func. for places
void search(string city)
{
    bool found = false;

    for (int i = 0; i < place.size(); i++)
    {
        if (place[i].city == city)
        {
            cout << place[i].barcode << endl;
            cout << place[i].startdate << endl;
            cout << place[i].enddate << endl;
            cout << place[i].stayduration << endl;
            cout << place[i].city << endl;
            cout << place[i].price << endl;
            cout << endl;
            found = true;
        }
    }
    if (found == false)
    {
        cout << "the place doesn't exist" << endl;
    }


}


//login for the admin
string adminlogin(string email, string password) {
    string pwd;
    int i = 0;
    for (i = 0; i < admin.size(); i++)
    {
        if (admin[i].mail == email)
        {
            pwd = admin[i].pass;
            break;
        }
    }
    if (i == admin.size()) {
        return "this mail does not exist";

    }
    if (pwd != password)
    {
        return "Wrong password";
    }
    return "successfully logged in";
}

//view data for admins
void viewadminsdata()
{
    for (int i = 0; i < admin.size(); i++)
    {
        cout << admin[i].name << endl;
        cout << admin[i].mail << endl;
        cout << admin[i].pass << endl;

    }
}
//view data for places
void viewplaces()
{
    for (int i = 0; i < place.size(); i++)
    {
        cout << place[i].barcode << endl;
        cout << place[i].startdate << endl;
        cout << place[i].enddate << endl;
        cout << place[i].stayduration << endl;
        cout << place[i].city << endl;
        cout << place[i].price << endl;

    }
}

//function to edit the startdate of places
void editSdate(string hbarcode, string newsdate) {
    for (int i = 0; i < place.size(); i++) {
        if (hbarcode == place[i].barcode) {
            place[i].startdate = newsdate;
        }
    }
}
//function to edit the enddate of places
void editEdate(string hbarcode, string newedate) {
    for (int i = 0; i < place.size(); i++) {
        if (hbarcode == place[i].barcode) {
            place[i].enddate = newedate;
        }
    }
}
//function to edit the stay duration of places
void editSd(string hbarcode, string newsduration) {
    for (int i = 0; i < place.size(); i++) {
        if (hbarcode == place[i].barcode) {
            place[i].stayduration = newsduration;
        }
    }
}
//function to edit the city of places
void editcity(string hbarcode, string newcity) {
    for (int i = 0; i < place.size(); i++) {
        if (hbarcode == place[i].barcode) {

            place[i].city = newcity;
        }
    }
}
//function to edit the price of places
void editprice(string hbarcode, string newprice) {
    for (int i = 0; i < place.size(); i++) {
        if (hbarcode == place[i].barcode) {
            place[i].price = newprice;
        }
    }
}



int main() {
    
    queue<user> m1;
    user u("momenna", "momenna15", "555", "menna", "mohamed", "18 10 2002");
    m1.push(u);
    

    //file for admins
    // Create a text string, which is used to output the text file
    string myText;
    Admin a = parr(myText);
    // Read from the text file
    ifstream MyReadFile("D:\\trail\\file\\admins.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
        admin.push_back(parr(myText));

    }

    // Close the file
    MyReadFile.close();


    //file for places
    string Text;
    places pll = par(Text);
    ifstream MyFile("D:\\trail\\file\\insertedplaces.txt");
    while (getline(MyFile, Text)) {
        place.push_back(par(Text));
    }
    MyFile.close();
    

    bool exitflag = false;
    cout << "*WELCOME*" << endl;
    cout << "The Homepage" << endl;
    cout << "1.Login as a traveler " << endl;
    cout << "2.Login as a host " << endl;
    cout << "3.Login as an admin " << endl;
    cout << "4.Register " << endl;
    cout << "5.Exit" << endl;
    cout << "Enter your choice" << endl;
    cout << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        //login
        bool status = users.login();
        if (status == false)
        {
            cout << "<error> Please enter a correct e-mail and password" << endl;
            return 0;
        }

       
        //search for place after logged in  as "traveler"
        cout << "search for the suitable place" << endl;
        cout << "type the city name in Egypt :" << endl;
        string scity;
        cin >> scity;
        cout << endl;
        search(scity);
            
        cout << endl;

        break;

    }

    case 2:
    {
        //login
        bool status =users.login();
        if (status == false)
        {
            cout << "<error> Please enter a correct e-mail and password" << endl;
            return 0;
        }
        //add places " host"
        cout << "Type the data of the place you want to insert " << endl;
        string brcode, stdate, eddate, sduration, pcity, pprice;
        ofstream insrtt("D:\\trail\\file\\insertedplaces.txt", ios::app);
        cout << "Type the barcode of the hotel:  ";
        cin >> brcode;
        cout << "Type the start date:  ";
        cin >> stdate;
        cout << "Type the End date  :  ";
        cin >> eddate;
        cout << "Type the duration  [2- days , 3-days ,..etc] :  ";
        cin >> sduration;
        cout << "Type the City in Egypt :  ";
        cin >> pcity;
        cout << "Type the price :  ";
        cin >> pprice;
        insrtt << brcode << "," << stdate << "," << eddate << "," << sduration << "," << pcity << "," << pprice << endl;

        insrtt.close();

        places pll(brcode, stdate, eddate, sduration, pcity, pprice);
        place.push_back(pll);

        cout << endl;
        break;
    }

    case 3:
    {
        string m, p;
        cout << "type your mail" << endl;
        cin >> m ;
        cout << "type your  password" << endl;
        cin >> p;
        string ADlogin = adminlogin(m, p);
        cout << ADlogin;
        cout << endl;

        if (ADlogin != "successfully logged in")
        {
            return 0;
        }
            
        cout << endl;
        //view , edit the data if logged in
            
        bool desicionexit = false;
        bool exit = false;
        bool back = false;
        int ch, choicee;
        while (!desicionexit)
        {

            cout << "press 1 to Edit the data" << endl;
            cout << "press 2 to view the data" << endl;
            cout << "3.Exit" << endl;
            cout << "Type your desicion" << endl;
            int d;
            cin >> d;
            switch (d)
            {
            case 1:
            {
                while (!exit)
                {
                    cout << "1.Edit the StartDate" << endl;
                    cout << "2.Edit the EndDate" << endl;
                    cout << "3.Edit the Stay Duration" << endl;
                    cout << "4.Edit the city" << endl;
                    cout << "5.Edit the price range" << endl;
                    cout << "6. back to the admin page " << endl;
                    cout << "Type your desicion" << endl;
                    cout << endl;
                    cin >> ch;
                    string bcode;
                    string var;

                    switch (ch)
                    {
                    case 1:
                    {
                        cout << "Type barcode of the hotel you want to edit" << endl;
                        cin >> bcode;
                        cout << "Type the new start date" << endl;
                        cin >> var;
                        editSdate(bcode, var);



                        break;
                    }
                    case 2:
                    {
                        cout << "Type barcode of the hotel you want to edit" << endl;
                        cin >> bcode;
                        cout << "Type the new end date" << endl;
                        cin >> var;
                        editEdate(bcode, var);
                        break;
                    }
                    case 3:
                    {
                        cout << "Type barcode of the hotel you want to edit" << endl;
                        cin >> bcode;
                        cout << "Type the new stay duration " << endl;
                        cin >> var;
                        editSd(bcode, var);

                        break;
                    }
                    case 4:
                    {
                        cout << "Type barcode of the hotel you want to edit" << endl;
                        cin >> bcode;
                        cout << "Type the new city " << endl;
                        cin >> var;
                        editcity(bcode, var);
                        break;
                    }
                    case 5:
                    {
                        cout << "Type barcode of the hotel you want to edit" << endl;
                        cin >> bcode;
                        cout << "Type the new price " << endl;
                        cin >> var;
                        editprice(bcode, var);
                        break;
                    }
                    case 6:
                        exit = true;
                    default:
                        break;
                    }
                    //clear the file
                    ofstream ofs;
                    ofs.open("D:\\trail\\file\\insertedplaces.txt", std::ofstream::out | std::ofstream::trunc);
                    ofs.close();
                    //rewrite the file
                    ofstream MyFile("D:\\trail\\file\\insertedplaces.txt");
                    for (int i = 0; i < place.size(); i++) 
                    {

                        MyFile << place[i].barcode + "," + place[i].startdate + "," + place[i].enddate + "," + place[i].stayduration + "," + place[i].city + ", " + place[i].price + "\n";

                    }
                    MyFile.close();


                }
                break;
            }

            case 2:
            {
                while (!back)
                {
                    cout << "1.view the places" << endl;
                    cout << "2.view the travelers" << endl;
                    cout << "3.view the hosts" << endl;
                    cout << "4.view the admins" << endl;
                    cout << "5.Back to the Admin page " << endl;
                    cout << "Type your desicion" << endl;
                    cout << endl;
                    cin >> choicee;
                    switch (choicee)
                    {
                    case 1:
                    {
                        viewplaces();
                        cout << endl;
                        break;
                    }
                    case 2:
                    {
                        string usertext;
                        ifstream MyFile("D:\\trail\\file\\usersdata.txt");
                        while (getline(MyFile, usertext)) {
                            cout<<usertext<<endl;
                        }
                        MyFile.close();
                        cout << endl;
                        break;
                    }
                    case 3:
                    {
                        string usertext;
                        ifstream MyFile("D:\\trail\\file\\usersdata.txt");
                        while (getline(MyFile, usertext)) {
                            cout << usertext << endl;
                        }
                        MyFile.close();
                        cout << endl;
                        break;
                    }
                    case 4:
                    {
                        viewadminsdata();
                        cout << endl;
                        break;
                    }
                    case 5:
                    {
                        back = true;
                        break;
                    }
                    default:
                        break;
                    }


                }

                break;
            }
            case 3:
            {
                desicionexit = true;
                break;
            }

            default:
                break;
            }



        }


        cout << endl;
        break;
    }
    case 4:
    {
       // register (sign up)
       users.registertion();
        //registertion();
      
            
        cout << endl;
        break;
    }
    case 5:
        exitflag = true;
        cout << endl;



    default:
        break;
    }


  return 0;
    
}
