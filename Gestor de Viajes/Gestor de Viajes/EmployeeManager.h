#pragma once
#include "Resident.h"
#include "Temporary.h"
#include <vector>
class EmployeeManager
{
	std::vector<Employee> employees;
	int size;
public:
	EmployeeManager();
	~EmployeeManager();
	void importEmployees();
	Employee* getEmployee(int id);
	void addEmployee(bool resident, std::string name, std::string surname, std::string email);
	void editEmployee(int id, std::string name, std::string surname, std::string email);
	void deleteEmployee(int id);
	int getSize();
	void createPDF();
	void sendEmail();

};

