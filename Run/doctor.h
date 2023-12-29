#pragma once
#include "worker.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class doctor : public worker
{
private:
	string doc_id;
	string department;

public:
	doctor();
};
