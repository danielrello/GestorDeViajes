#include "GestordeViajes.h"
#include <QtWidgets/QApplication>
#include "EmployeeManager.h"
#include "Database.h"
#define DEBUG

#ifdef DEBUG
#include <Windows.h>
#include <stdio.h>
#endif // DEBUG


using namespace std;



int main(int argc, char *argv[])
{
	
#ifdef DEBUG
	FreeConsole();
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);
	freopen("CON", "w", stderr);
	freopen("CON", "r", stdin);
#endif // DEBUG

	QApplication a(argc, argv);

	QSqlDatabase *db = new QSqlDatabase;

	setDataBase(db);

	bool running = true;
	int option;

	string name, surname, email;
	int id, lastID;
	char *type = new char [20];
	bool resident;

	EmployeeManager *manager = new EmployeeManager;

	readDataBase(manager);

	GestordeViajes w;
	//w.show();
	while (running == true) {
		cout << "1. Add new Employee" << endl;
		cout << "2. Delete Employee" << endl;
		cout << "3. Edit Employee" << endl;
		cout << "4. View Employee list" << endl;
		cout << "0. Exit" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Insert Employee name: ";
			cin >> name;
			cout << "Insert Employee surname: ";
			cin >> surname;
			cout << "Insert Employee email: ";
			cin >> email;
			cout << "Is resident?: ";
			cin >> resident;
			lastID = manager->getLastID() + 1;
			manager->addEmployee(resident, lastID,name, surname, email);
			manager->setLastID(lastID);
			break;
		case 2:
			cout << "Insert Employee id: ";
			cin >> id;
			manager->deleteEmployee(id);
			break;
		case 3:
			cout << "Insert Employee id: ";
			cin >> id;
			cout << "You are changing employee " << manager->getEmployee(id)->getName() << endl;
			cout << "Insert new name: ";
			cin >> name;
			cout << "Insert new surname: ";
			cin >> surname;
			cout << "Insert new email: ";
			cin >> email;
			manager->editEmployee(id, name, surname, email);
		case 4:
			for (int i = 0; i < manager->getEmployees().size(); i++) {
				manager->getEmployees()[i]->print();
			}
			break;
		case 0:
			running = false;
			break;
		default:
			break;
		}
	}
	system("pause");
	return a.exec();
}
