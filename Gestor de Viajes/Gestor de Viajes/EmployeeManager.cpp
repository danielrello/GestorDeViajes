#include "EmployeeManager.h"
#include "Database.h"


int EmployeeManager::getPos(int id)
{
	int pos = -1;
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getID() == id)
			pos = i;
	}
	return pos;
}

EmployeeManager::EmployeeManager()
{
	lastID = 0;
	loadingDataBase = true;
}


EmployeeManager::~EmployeeManager()
{
}

void EmployeeManager::setLoading(bool loading)
{
	loadingDataBase = loading;
}

Employee * EmployeeManager::getEmployee(int id)
{
	Employee * employee = nullptr;
	int pos = getPos(id);
	if (pos != -1) {
		employee = employees[pos];
	}
	return employee;
}

void EmployeeManager::addEmployee(bool resident, int id, std::string name, std::string surname, std::string email)
{
	if (resident) {
		Resident *nuevoEmpleado = new Resident(name, surname, email, id);
		if(!loadingDataBase)
			nuevoEmpleado->Update();
		employees.emplace_back(nuevoEmpleado);
	}
	else {
		Temporary *nuevoEmpleado = new Temporary(name, surname, email, id);
		if(!loadingDataBase)
			nuevoEmpleado->Update();
		employees.emplace_back(nuevoEmpleado);
	}
}

void EmployeeManager::editEmployee(int id, std::string name, std::string surname, std::string email)
{
	if (getEmployee(id) == nullptr) {
		cout << "The employee with id: " << id << " does not exist."<< endl;
	}
	else {
		getEmployee(id)->setName(name);
		getEmployee(id)->setSurname(surname);
		getEmployee(id)->setEmail(email);
		getEmployee(id)->Update();
	}
}

void EmployeeManager::deleteEmployee(int id)
{
	int posToDelete = getPos(id);
	if (posToDelete != -1) {
		cout << "PosToDelete: " << posToDelete << endl;
		getEmployee(id)->Update();
		employees.erase(employees.begin() + (posToDelete));
	}
	else {
		cout << "The employee with id: " << id << " does not exist." << endl;
	}
}

int EmployeeManager::getLastID()
{
	return lastID;
}

void EmployeeManager::setLastID(int id)
{
	this->lastID = id;
}

std::vector<Employee*> EmployeeManager::getEmployees()
{
	return employees;
}
