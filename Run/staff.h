#pragma once
#include "worker.h"
#include <iostream>
#include <string>
using namespace std;
class staff : public worker
{

private:
	int stff_id;
	string position;

public:
	staff();
};
