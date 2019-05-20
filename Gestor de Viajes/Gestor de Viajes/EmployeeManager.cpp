#include "EmployeeManager.h"
#include "Database.h"


EmployeeManager::EmployeeManager()
{
	size = 0;
}


EmployeeManager::~EmployeeManager()
{
}

Employee * EmployeeManager::getEmployee(int id)
{
	Employee * empleado;
	for(int i = 0; i < getSize(); i++){
		if (employees[i].getID() == id)
			empleado = &employees[i];
	}
	return empleado;
}

void EmployeeManager::addEmployee(bool resident, std::string name, std::string surname, std::string email)
{
	char **data = (char**)malloc(sizeof(char) * 3);
	for (int i = 0; i < 4; i++) {
		data[i] = new char[50];
	}
	string id = to_string(getSize());
	id.copy(data[0], id.size());
	data[0][id.size()] = '\0';
	name.copy(data[1], name.size());
	data[1][name.size()] = '\0';
	surname.copy(data[2], surname.size());
	data[2][surname.size()] = '\0';
	email.copy(data[3], email.size());
	data[3][email.size()] = '\0';

	if (resident) {
		Resident nuevoEmpleado(name, surname, email, getSize());
		employees.emplace_back(nuevoEmpleado);
		insertQuery(data, RESIDENT);
	}
	else {
		Temporary nuevoEmpleado(name, surname, email, getSize());
		employees.emplace_back(nuevoEmpleado);
		insertQuery(data, TEMPORARY);
	}
	size++;
}

void EmployeeManager::editEmployee(int id, std::string name, std::string surname, std::string email)
{
	getEmployee(id)->setName(name);
	getEmployee(id)->setSurname(surname);
	getEmployee(id)->setEmail(email);
}

void EmployeeManager::deleteEmployee(int id)
{
	getEmployee(id);
}

int EmployeeManager::getSize()
{
	return size;
}
