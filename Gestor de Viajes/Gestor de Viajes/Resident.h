#pragma once
#include "Employee.h"
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlDriver>
#include <Qtsql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QtSql/qsqlrecord.h>
#include <qdebug.h>

using namespace std;

class Resident : public Employee {
public:
	Resident(string name, string surname, string email, int id) : Employee(name, surname, email, id) {};
	bool isResident() { return true; }
	void print(){
		std::cout << id << " | " << name << " | " << surname << " | " << email << " | " << "Resident" << std::endl;
	}
};