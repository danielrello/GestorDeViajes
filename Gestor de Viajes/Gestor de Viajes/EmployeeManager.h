#pragma once
#include "Resident.h"
#include "Temporary.h"
#include <vector>
class EmployeeManager
{
	std::vector<Employee*> employees;
	int size;
	int getPos(int id);
	bool loadingDataBase;
public:
	EmployeeManager();
	~EmployeeManager();
	void importEmployees();
	void setLoading(bool loading);
	Employee* getEmployee(int id);
	void addEmployee(bool resident, int id,std::string name, std::string surname, std::string email);
	void editEmployee(int id, std::string name, std::string surname, std::string email);
	void deleteEmployee(int id);
	int getSize();
	void createPDF();
	void sendEmail();

};

