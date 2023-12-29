/*
========================================
a- Mosab Mohamed
b- Mahmoud Abd-Elmenem
c- Mahmoud Khaled
d- Mostafa Salah
e- Abd-Elrahman Yahya
=======================================
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include "person.h"
#include "worker.h"
#include "doctor.h"
#include "nurse.h"
#include "staff.h"
#include "patient.h"
#include "person.cpp"
#include "worker.cpp"
#include "doctor.cpp"
#include "nurse.cpp"
#include "staff.cpp"
#include "patient.cpp"
using namespace std;
void menu();
void patient_option();
void Old_Patient();
void New_Patient();
void worker_option();
void doc_options();
void Old_Doctor();
void New_Doctor();
void nurse_options();
void Old_Nurse();
void New_Nurse();
void staff_options();
void Old_Staff();
void New_Staff();
// main function
int main()
{
    int x;
    string username, password;

    // Welcome message
    cout << setfill('=') << setw(50) << "" << endl;
    cout << "=========== Hello in Hospital Program ============\n";
    cout << setfill('=') << setw(50) << "" << endl;

    // login user
    do
    {
        cout << "Enter Username : ";
        cin >> username;
        for (int i = 0; i < username.size(); i++)
        {
            username[i] = toupper(username[i]);
        }
        cout << "Enter password : ";
        cin >> password;
        if (!(username == "A4M" && password == "0000"))
        {
            system("cls");
            cout << "\"Worng password or username\"\n";
        }
    } while (!((username == "A4M") && (password == "0000")));

    // start the program
    menu();
    return 0;
}
//-----------------------------------------------------------------------------------------------------------
// menu function

void menu()
{
    int x;
    do
    {
        cout << "=================================\n[1] worker\n[2] paitent\n[3] Exit\n=================================\n";
        cin >> x;
        // clear the terminal
        system("cls");
        if (x == 1)
        {
            worker_option();
        }
        else if (x == 2)
        {
            patient_option();
        }
        else if (x == 3)
        {
            return;
        }
    } while ((x < 1) || (x > 3));
}
//-----------------------------------------------------------------------------------------------------------
// patient function

void patient_option()
{
    int n;
    do
    {
        cout << "=================================\n[1] Old Patient\n[2] New Patient\n[3] Previous Page\n=================================\n";
        cin >> n;
        system("cls");
        if (n == 1)
        {
            Old_Patient();
        }
        else if (n == 2)
        {
            New_Patient();
        }
        else if (n == 3)
        {
            menu();
        }

    } while ((n < 1) || (n > 3));
}
void Old_Patient()
{
    int n;
    do
    {
        cout << "=================================\n[1] Get data\n[2] Previous Page\n=================================\n";
        cin >> n;
        system("cls");
        if (n == 1)
        {
            string id;
            cout << "enter your id : ";
            cin >> id;
            patient obj;
            obj.print_data(id);
        }
        else if (n == 2)
        {
            patient_option();
        }

    } while ((n < 1) || (n > 2));
    menu();
}
void New_Patient()
{
    int n;
    do
    {
        cout << "=================================\n[1] Set Data \n[2] Previous Page\n=================================\n";
        cin >> n;
        system("cls");
        if (n == 1)
        {
            patient obj;
            obj.set_data();
        }
        else if (n == 2)
        {
            patient_option();
        }
    } while ((n < 1) || (n > 2));
    menu();
}
//-----------------------------------------------------------------------------------------------------------
// worker function

void worker_option()
{
    int x;
    do
    {
        cout << "=================================\n[1] Doctor\n[2] nurse\n[3] staff\n[4] Previous Page\n=================================\n";
        cin >> x;
        system("cls");
        if (x == 1)
        {
            doc_options();
        }
        else if (x == 2)
        {
            nurse_options();
        }
        else if (x == 3)
        {
            staff_options();
        }
        else if (x == 4)
        {
            menu();
        }

    } while (x < 1 || x > 4);
}
//----------------------------------------------------------------
// doc_options function

void doc_options()
{
    int n;
    do
    {
        cout << "=================================\n[1] Old Doctor\n[2] New Doctor\n[3] Previous Page\n=================================\n";
        cin >> n;
        system("cls");
        if (n == 1)
        {
            Old_Doctor();
        }
        else if (n == 2)
        {
            New_Doctor();
        }
        else if (n == 3)
        {
            worker_option();
        }
    } while ((n < 1) || (n > 3));
}
void Old_Doctor()
{
    int n;
    do
    {
        cout << "=================================\n[1] Get data\n[2] Previous Page\n=================================\n";
        cin >> n;
        system("cls");
        if (n == 1)
        {
            string id, file_name = "doctor.txt";
            cout << "Enter your id : ";
            cin >> id;
            doctor obj;
            obj.print_data(id, file_name);
        }
        else if (n == 2)
        {
            doc_options();
        }
    } while ((n < 1) || (n > 2));
    menu();
}
void New_Doctor()
{
    int n;
    do
    {
        cout << "=================================\n[1] Set Data\n[2] Previous Page\n=================================\n";
        cin >> n;
        system("cls");
        if (n == 1)
        {
            string file_name = "doctor.txt";
            doctor obj;
            obj.set_data(file_name);
        }
        else if (n == 2)
        {
            doc_options();
        }
    } while ((n < 1) || (n > 2));
    menu();
}
//----------------------------------------------------------------
// nurse menu

void nurse_options()
{
    int n;
    do
    {
        cout << "=================================\n[1] Old Nurse\n[2] New Nurse\n[3] Previous Page\n=================================\n";
        cin >> n;
        system("cls");
        if (n == 1)
        {
            Old_Nurse();
        }
        else if (n == 2)
        {
            New_Nurse();
        }
        else if (n == 3)
        {
            worker_option();
        }
    } while ((n < 1) || (n > 3));
}
void Old_Nurse()
{
    int n;
    do
    {
        cout << "=================================\n[1] Get data\n[2] Previous Page\n=================================\n";
        cin >> n;
        system("cls");
        if (n == 1)
        {
            string file_name = "nurse.txt";
            string id;
            cout << "enter your id : ";
            cin >> id;
            nurse obj;
            obj.print_data(id, file_name);
        }
        else if (n == 2)
        {
            nurse_options();
        }

    } while ((n < 1) || (n > 2));
    menu();
}
void New_Nurse()
{
    string file_name = "nurse.txt";
    int n;
    do
    {
        cout << "=================================\n[1] Set Data\n[2] Previous Page\n=================================\n";
        cin >> n;
        system("cls");
        if (n == 1)
        {
            nurse obj;
            obj.set_data(file_name);
        }
        else if (n == 2)
        {
            nurse_options();
        }
    } while ((n < 1) || (n > 2));
    menu();
}
//----------------------------------------------------------------
// staff menu

void staff_options()
{
    int n;
    do
    {
        cout << "=================================\n[1] Old staff\n[2] New staff\n[3] Previous Page\n=================================\n";
        cin >> n;
        system("cls");
        if (n == 1)
        {
            Old_Staff();
        }
        else if (n == 2)
        {
            New_Staff();
        }
        else if (n == 3)
        {
            worker_option();
        }

    } while ((n < 1) || (n > 3));
}

void Old_Staff()
{
    int n;
    string file_name = "staff.txt";
    do
    {
        cout << "=================================\n[1] Get data\n[2] Previous Page\n=================================\n";
        cin >> n;
        system("cls");
        if (n == 1)
        {
            string id;
            cout << "enter your id : ";
            cin >> id;
            staff obj;
            obj.print_data(id, file_name);
        }
        else if (n == 2)
        {
            staff_options();
        }

    } while ((n < 1) || (n > 2));
    menu();
}
void New_Staff()
{
    int n;
    string file_name = "staff.txt";
    do
    {
        cout << "=================================\n[1] Set Data\n[2] Previous Page\n=================================\n";
        cin >> n;
        system("cls");
        if (n == 1)
        {
            staff obj;
            obj.set_data(file_name);
        }
        else if (n == 2)
        {
            staff_options();
        }
    } while ((n < 1) || (n > 2));
    menu();
}
//----------------------------------------------------------------