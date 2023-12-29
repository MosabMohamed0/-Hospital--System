#pragma once
#include "person.h"
#include <string>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class patient : public person
{
private:
    string disease, charges;

public:
    patient();
    string generat_id();
    string set_data();
    void if_exit(string id);
    void print_data(string id);
    vector<string> get_id();
};
