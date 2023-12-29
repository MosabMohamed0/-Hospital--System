#pragma once
#include "worker.h"
#include "person.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class worker : public person
{
protected:
	int salary;
	string department;

public:
	worker();
	string generat_id(string file_name);
	string set_data(string file_name);
	vector<string> get_id(string file_name);
	void if_exit(string id,string file_name);
	void print_data(string id,string file_name);
};
