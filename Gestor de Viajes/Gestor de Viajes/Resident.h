#pragma once
#include "Employee.h"
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlDriver>
#include <Qtsql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QtSql/qsqlrecord.h>
#include <qdebug.h>
#include "Travel.h"

using namespace std;

class Resident : public Employee {
	vector<Travel*> travels;
public:
	Resident(string name, string surname, string email, int id) : Employee(name, surname, email, id) {};
	bool isResident() { return true; }
	void print(){
		std::cout << id << " | " << name << " | " << surname << " | " << email << " | " << "Resident" << " | TravelNumbers: " << travels.size() << std::endl;
	}
	void linkTravel(Travel * travel)
	{
		bool notLinked = true;
		for (int i = 0; i < travels.size(); i++) {
			if (travels[i]->getID() == travel->getID()) {
				notLinked = false;
			}
		}
		if (notLinked) {
			travels.emplace_back(travel);
			QSqlQuery query;
			query.prepare(QString(
				"UPDATE travel SET idEmployee=%1 "
				"WHERE id=%2")
				.arg(id)
				.arg(travel->getID()));
			if (!query.exec())
				qDebug() << query.lastError().text();
		}else{
			cout << "This travel is already linked" << endl;
		}
	}
	vector<Travel*> getTravels() { return travels; };
};