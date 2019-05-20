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
	if (resident) {
		Resident nuevoEmpleado(name, surname, email, getSize());
		employees.emplace_back(nuevoEmpleado);

	}
	else {
		Temporary nuevoEmpleado(name, surname, email, getSize());
		employees.emplace_back(nuevoEmpleado);
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
