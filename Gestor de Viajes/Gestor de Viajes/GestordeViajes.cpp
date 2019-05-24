#include "GestordeViajes.h"
#include "EmployeeManagement.h"

GestordeViajes::GestordeViajes(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.exitButton, SIGNAL(clicked()), this, SLOT(exit()));
	connect(ui.employeeManagerB, SIGNAL(clicked()), this, SLOT(employeeManagement()));
}

void GestordeViajes::exit() {
	QApplication::exit();
}

void GestordeViajes::employeeManagement() {
	EmployeeManagement *employeeWindow = new EmployeeManagement(this);
	employeeWindow->show();
	this->hide();
}