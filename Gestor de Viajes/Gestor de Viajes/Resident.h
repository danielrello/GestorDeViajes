#pragma once
#include "Employee.h"

using namespace std;

class Resident : public Employee {
public:
	Resident(string name, string surname, string email, int id) : Employee(name, surname, email, id) {};
	bool isResident() { return true; }
};