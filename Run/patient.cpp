#include "patient.h"
#include "person.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//---------------------------------------------------------------------------------------
// generate a new id. 

patient::patient() {}
string patient::generat_id()
{

    ifstream inputFile("patient.txt");
    string line;
    // start with 2 becouse the id start with 1
    int lineCount = 2;
    // bt3ed alstor ile fe el file
    while (getline(inputFile, line))
    {
        lineCount++;
    }
    inputFile.close();
    return to_string(99998 + lineCount);
}
//---------------------------------------------------------------------------------------
// get data from terminal and store it in the specified file.

string patient::set_data()
{
    string id_generated = generat_id();
    string id, fname, sname, disease, gender, age, charges;
    ofstream myfile("patient.txt", ios::out | ios::app);
    cout << "enter your first name and secound name : ";
    cin >> fname >> sname;
    cout << "enter your age : ";
    cin >> age;
    cout << "enter your gender : ";
    cin >> gender;
    cout << "enter your disease : ";
    cin >> disease;
    cout << "enter your charges : ";
    cin >> charges;
    cout << "your id is : " << id_generated<<endl;
    myfile << id_generated << " " << fname << " " << sname << " " << age << " " << gender << " " << disease << " " << charges << " "
           << "\n";
    myfile.close();
    return id;
}
//---------------------------------------------------------------------------------------
//subatruct the id from the specified file and stor in vector and send it to "get_id" function.

vector<string> patient::get_id()
{
    string data, id;
    vector<string> data_id;
    ifstream your_file("patient.txt");
    while (getline(your_file, data))
    {
        id = data.substr(0, data.find(' '));
        data_id.push_back(id);
    }
    your_file.close();
    return data_id;
}
//---------------------------------------------------------------------------------------
// print the data in termial

void patient::print_data(string id)
{
    int flag = 0;
    string data;
    int space[6];
    fstream outfile("patient.txt", ios::in | ios::out | ios::app);
    while (!outfile.eof())
    {
        getline(outfile, data);
        if (id == data.substr(0, data.find(' ')))
        {
            flag = 1;
            cout << "your data is " << endl;
            space[0] = data.find(' ');
            cout << "your first name is : " << data.substr(space[0] + 1, data.find(' ', space[0] + 1) - space[0] - 1) << endl;

            space[1] = data.find(' ', space[0] + 1);
            cout << "your second name is : " << data.substr(space[1] + 1, data.find(' ', space[1] + 1) - space[1] - 1) << endl;

            space[2] = data.find(' ', space[1] + 1);
            cout << "your age is : " << data.substr(space[2] + 1, data.find(' ', space[2] + 1) - space[2] - 1) << endl;

            space[3] = data.find(' ', space[2] + 1);
            cout << "your gender is : " << data.substr(space[3] + 1, data.find(' ', space[3] + 1) - space[3] - 1) << endl;

            space[4] = data.find(' ', space[3] + 1);
            cout << "your disease is : " << data.substr(space[4] + 1, data.find(' ', space[4] + 1) - space[4] - 1) << endl;

            space[5] = data.find(' ', space[4] + 1);
            cout << "your charges are : " << data.substr(space[5] + 1, data.find(' ', space[5] + 1) - space[5] - 1) << endl;
            
            break;
        }
    }
    if (flag == 0)
    {
        cout << "\"Data Not Found\"\n";
    }
}
//---------------------------------------------------------------------------------------
// check if this id is exist in our system

void patient::if_exit(string id)
{
    int flage = 0;
    vector<string> data;
    data = get_id();
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == id)
        {
            flage = 1;
            print_data(id);
            break;
        }
    }
    if (flage == 0)
    {
        cout << "\"Data Not Found\"\n";
    }
}