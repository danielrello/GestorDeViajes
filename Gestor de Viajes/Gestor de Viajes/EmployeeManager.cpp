#include "EmployeeManager.h"
#include "Functions.h"
#include <string>
#include <fstream>
#include <sstream>

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
	lastID = -1;
	loadingDataBase = true;
}


EmployeeManager::~EmployeeManager()
{
}

int EmployeeManager::importEmployees(const char* filePath)
{
	fstream file;
	file.open(filePath, ios::in);
	int count = 0;
	vector<Employee*> employees;
	if (!file.is_open()) {
		cout << "No se puedo abrir el archivo." << endl;
		return count;
	}

	vector<vector<string>> info;
	string line;
	while (getline(file, line))                   // read a whole line of the file
	{
		stringstream ss(line);     
		string data;                // put it in a stringstream (internal stream)
		vector<string>row;

		row.clear();
		
		while (getline(ss, data, ';'))           // read (string) items up to a semmicolon
		{
			row.push_back(data);
		}
		if (row.size() == 4) info.push_back(row);  
		else {
			cout << "Se ha descartado la línea " << count << " por falta de argumentos" << endl;
			count--;
		}// add non-empty rows to matrix
	}
	for (int i = 1; i < info.size(); i++) {
		addEmployee(stoi(info[i][3]), getLastID() + 1, info[i][0], info[i][1], info[i][2]);
		employees.emplace_back(getEmployee(getLastID()));
		count++;
	}

	if (count == 0)
		cout << "Empty CSV\n";
	return count;
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
	lastID = id;
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
	lastID = id;
}

std::vector<Employee*> EmployeeManager::getEmployees()
{
	return employees;
}
