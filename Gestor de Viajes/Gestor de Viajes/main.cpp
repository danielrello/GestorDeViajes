#include "GestordeViajes.h"
#include <QtWidgets/QApplication>
#include "EmployeeManager.h"
#include "TravelManager.h"
#include "Functions.h"
//#define DEBUG

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
	bool isResident;


	string departureLocation, arrivalLocation, departureTime, arrivalTime;
	int cost;

	EmployeeManager *manager = new EmployeeManager;
	TravelManager *travelManager = new TravelManager;

	Resident *resident;
	string file;
	readDataBase(manager, travelManager);

	GestordeViajes w;
	w.addManagers(travelManager, manager);
	w.show();

#ifdef DEBUG
	while (running == true) {
		cout << "1. Add new Employee" << endl;
		cout << "2. Delete Employee" << endl;
		cout << "3. Edit Employee" << endl;
		cout << "4. View Employee list" << endl;
		cout << "5. Add new Travel" << endl;
		cout << "6. Delete Travel" << endl;
		cout << "7. Edit Travel" << endl;
		cout << "8. View Travel list" << endl;
		cout << "9. Link Travel" << endl;
		cout << "10. See Employee Travels" << endl;
		cout << "11. Import Employees" << endl;
		cout << "12. Import Travels" << endl;
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
			cin >> isResident;
			lastID = manager->getLastID() + 1;
			manager->addEmployee(isResident, lastID, name, surname, email);
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
			break;
		case 4:
			for (int i = 0; i < manager->getEmployees().size(); i++) {
				manager->getEmployees()[i]->print();
			}
			break;
		case 5:
			cout << "Insert Travel Departure Location: ";
			cin >> departureLocation;
			cout << "Insert Travel Arrival Location: ";
			cin >> arrivalLocation;
			getchar();
			cout << "Insert Travel Departure Time with format (yyyy-mm-dd hh:mm:ss): ";
			getline(std::cin, departureTime);
			cout << "Insert Travel Arrival Time with format (yyyy-mm-dd hh:mm:ss): ";
			getline(std::cin, arrivalTime);
			cout << "Insert Travel Cost: ";
			cin >> cost;
			lastID = manager->getLastID() + 1;
			manager->setLastID(lastID);
			travelManager->addTravel(lastID, departureLocation, arrivalLocation, departureTime, arrivalTime, cost);
			break;
		case 6:
			cout << "Insert Travel id: ";
			cin >> id;
			travelManager->deleteTravel(id);
			break;
		case 7:
			cout << "Insert Travel id: ";
			cin >> id;
			cout << "You are changing travel " << travelManager->getTravel(id)->getDepartureLocation() << "-" << travelManager->getTravel(id)->getArrivalLocation() << endl;
			cout << "Insert new Travel Departure Location: ";
			cin >> departureLocation;
			cout << "Insert new Travel Arrival Location: ";
			cin >> arrivalLocation;
			cout << "Insert new Travel Departure Time with format (yyyy/mm/dd hh:mm:ss): ";
			cin >> departureTime;
			cout << "Insert new Travel Arrival Time with format (yyyy/mm/dd hh:mm:ss):: ";
			getchar();
			cin >> arrivalTime;
			cout << "Insert new Travel Cost: ";
			cin >> cost;
			travelManager->editTravel(id, departureLocation, arrivalLocation, departureTime, arrivalTime, cost);
			break;
		case 8:
			for (int i = 0; i < travelManager->getTravels().size(); i++) {
				travelManager->getTravels()[i]->print();
			}
			break;
		case 9:
			cout << "Insert Resident Employee id: ";
			cin >> id;
			if (manager->getEmployee(id) != nullptr) {
				if (manager->getEmployee(id)->isResident()) {
					resident = (Resident*)manager->getEmployee(id);
				}
				else {
					cout << "Employee must be resident." << endl;
					break;
				}
				cout << "Insert Travel id: ";
				cin >> lastID;
				if (travelManager->getTravel(lastID) != nullptr) {
					resident->linkTravel(travelManager->getTravel(lastID));
					cout << "Travel:" << endl;
					travelManager->getTravel(lastID)->print();
					cout << "Linked to: " << endl;
					manager->getEmployee(id)->print();
				}
				else {
					cout << "Travel selected does not exists." << endl;
				}
			}
			else {
				cout << "Employee selected does not exists." << endl;
			}
			break;
		case 10:
			cout << "Insert Resident Employee id: ";
			cin >> id;
			if (manager->getEmployee(id) != nullptr) {
				if (manager->getEmployee(id)->isResident()) {
					resident = (Resident*)manager->getEmployee(id);
				}
				else {
					cout << "Employee must be resident." << endl;
					break;
				}
				for (int i = 0; i < resident->getTravels().size(); i++) {
					resident->getTravels()[i]->print();
				}
			}
			else {
				cout << "Employee selected does not exists." << endl;
			}
			break;
		case 11:
			cout << "Insert file path: " << endl;
			cin >> file;
			manager->importEmployees(file.data());
			break;
		case 12:
			cout << "Insert file path: ";
			cin >> file;
			travelManager->setLastID(manager->getLastID());
			travelManager->importTravels(file.data());
			break;
		case 0:
			running = false;
			break;
		default:
			break;
		}
}

#endif // DEBUG

	return a.exec();
}
