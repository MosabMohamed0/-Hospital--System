#include "worker.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
worker::worker() {}
//---------------------------------------------------------------------------------------
// generate a new id.

string worker::generat_id(string file_name)
{
    fstream inputFile(file_name, ios::in);
    string line;
    // start with 2 because the id start with 1
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

string worker::set_data(string file_name)
{
    string id_generated = generat_id(file_name);
    string id, fname, sname, department, gender, age, salary;
    fstream myfile(file_name, ios::out | ios::app);
    cout << "enter your first name and second name : ";
    cin >> fname >> sname;
    cout << "enter your age : ";
    cin >> age;
    cout << "enter your gender : ";
    cin >> gender;
    cout << "enter your department : ";
    cin >> department;
    cout << "enter your salary : ";
    cin >> salary;
    cout << "your id is : " << id_generated << endl;
    myfile << id_generated << " " << fname << " " << sname << " " << age << " " << gender << " " << department << " " << salary << " "
           << "\n";
    myfile.close();
}
//---------------------------------------------------------------------------------------
// subatruct the id from the specified file and stor in vector and send it to "get_id" function.

vector<string> worker::get_id(string file_name)
{
    string data, id;
    vector<string> data_id;
    fstream your_file(file_name, ios::out);
    while (getline(your_file, data))
    {
        id = data.substr(0, data.find(' '));
        data_id.push_back(id);
    }
    your_file.close();
    return data_id;
}
//---------------------------------------------------------------------------------------
// check if this id is exist in our system

void worker::if_exit(string id,string file_name)
{
    int flage = 0;
    vector<string> data;
    data = get_id(file_name);
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == id)
        {
            flage = 1;
            print_data(id, file_name);
            break;
        }
    }
    if (flage == 0)
    {
        cout << "\"Data Not Found\"\n";
    }
}
//---------------------------------------------------------------------------------------
// print the data in termial

void worker::print_data(string id, string file_name)
{
    string data;
    int flag = 0;
    int space[6];
    fstream outfile(file_name, ios::in | ios::out | ios::app);
    while (!outfile.eof())
    {
        getline(outfile, data);
        if (id == data.substr(0, data.find(' ')))
        {
            flag = 1;

            cout << "your data is " << endl;
            space[0] = data.find(' ');
            cout << "your first name is :  " << data.substr(space[0] + 1, data.find(' ', space[0] + 1) - space[0] - 1) << endl;

            space[1] = data.find(' ', space[0] + 1);
            cout << "your second name is :  " << data.substr(space[1] + 1, data.find(' ', space[1] + 1) - space[1] - 1) << endl;

            space[2] = data.find(' ', space[1] + 1);
            cout << "your age is :  " << data.substr(space[2] + 1, data.find(' ', space[2] + 1) - space[2] - 1) << endl;

            space[3] = data.find(' ', space[2] + 1);
            cout << "your gender is :  " << data.substr(space[3] + 1, data.find(' ', space[3] + 1) - space[3] - 1) << endl;

            space[4] = data.find(' ', space[3] + 1);
            cout << "your department is :  " << data.substr(space[4] + 1, data.find(' ', space[4] + 1) - space[4] - 1) << endl;

            space[5] = data.find(' ', space[4] + 1);
            cout << "your salary is :  " << data.substr(space[5] + 1, data.find(' ', space[5] + 1) - space[5] - 1) << endl;

            break;
        }
    }
    if (flag == 0)
    {
        cout << "\"Data Not Found\"\n";
    }
}