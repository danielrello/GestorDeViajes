#pragma once
#include "Employee.h"

using namespace std;

class Temporary : public Employee {
public:
	Temporary(string name, string surname, string email, int id) : Employee(name, surname, email, id) {};
	bool isResident() { return false; };
};