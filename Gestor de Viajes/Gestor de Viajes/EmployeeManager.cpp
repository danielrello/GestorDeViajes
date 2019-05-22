#include "EmployeeManager.h"
#include "Database.h"


int EmployeeManager::getPos(int id)
{
	int pos = 0;
	for (int i = 0; i < getSize(); i++) {
		if (employees[i]->getID() == id)
			pos = i;
	}
	return pos;
}

EmployeeManager::EmployeeManager()
{
	size = 0;
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
	return employees[getPos(id)];
}

void EmployeeManager::addEmployee(bool resident, int id,std::string name, std::string surname, std::string email)
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
	size++;
}

void EmployeeManager::editEmployee(int id, std::string name, std::string surname, std::string email)
{
	if (getEmployee(id) == nullptr) {
		cout << "No se encuentra al empleado con el id: " << id << endl;
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
	cout << posToDelete << endl;
	getEmployee(id)->Update();
	employees.erase(employees.begin() + (posToDelete - 1));
}

int EmployeeManager::getSize()
{
	return size;
}
