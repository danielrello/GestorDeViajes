#include "GestordeViajes.h"
#include "EmployeeWindow.h"

GestordeViajes::GestordeViajes(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	employeeManager = new EmployeeManager();
	travelManager = new TravelManager();
	connect(ui.exitButton, SIGNAL(clicked()), this, SLOT(exit()));
	connect(ui.employeeManagerB, SIGNAL(clicked()), this, SLOT(employeeManagement()));
}

void GestordeViajes::addManagers(TravelManager * travelManager, EmployeeManager * employeeManager)
{
	this->travelManager = travelManager;
	this->employeeManager = employeeManager;
}

void GestordeViajes::exit() {
	QApplication::exit();
}

void GestordeViajes::employeeManagement() {
	EmployeeWindowClass *employeeWindow = new EmployeeWindowClass(this);
	employeeWindow->show();
	this->hide();
}