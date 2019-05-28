#include "GestordeViajes.h"
#include "EmployeeWindow.h"
#include "TravelWindow.h"
#include "qfiledialog.h"
#include "qmessagebox.h"

GestordeViajes::GestordeViajes(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	employeeManager = new EmployeeManager();
	travelManager = new TravelManager();
	connect(ui.exitButton, SIGNAL(clicked()), this, SLOT(exit()));
	connect(ui.employeeManagerB, SIGNAL(clicked()), this, SLOT(employeeManagement()));
	connect(ui.travelManagerB, SIGNAL(clicked()), this, SLOT(travelManagement()));
	connect(ui.importEmployeeButton, SIGNAL(clicked()), this, SLOT(importEmployees()));
	connect(ui.importTravelsButton, SIGNAL(clicked()), this, SLOT(importTravels()));
}

void GestordeViajes::addManagers(TravelManager * travelManager, EmployeeManager * employeeManager)
{
	this->travelManager = travelManager;
	this->employeeManager = employeeManager;
	Update();
}

TravelManager* GestordeViajes::getTravelManager()
{
	return travelManager;
}

EmployeeManager * GestordeViajes::getEmployeeManager()
{
	return employeeManager;
}

void GestordeViajes::Update()
{
	ui.employeeCountLabel->setText(QString::fromStdString(to_string((int)employeeManager->getEmployees().size())));
	ui.employeeCountLabel_2->setText(QString::fromStdString(to_string((int)travelManager->getTravels().size())));
}

void GestordeViajes::importTravels()
{
	QStringList fileName;
	QFileDialog dialog(this);
	QStringList filters;
	int count;
	filters << "CSV files (*.csv)"
		<< "Any files (*)";
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setNameFilters(filters);
	if (dialog.exec())
		fileName = dialog.selectedFiles();
	else {
		return;
	}
	count = travelManager->importTravels((fileName[0].toStdString()).c_str());
	QMessageBox::information(this, "Imported Travels", QString("Travels succesfully imported:\nTotal Travels: " ) + QString::number(count), QMessageBox::Ok);
	Update();
}

void GestordeViajes::importEmployees()
{
	QStringList fileName;
	QFileDialog dialog(this);
	QStringList filters;
	int count;
	filters << "CSV files (*.csv)"
		<< "Any files (*)";
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setNameFilters(filters);
	if (dialog.exec())
		fileName = dialog.selectedFiles();
	else {
		return;
	}
	count = employeeManager->importEmployees((fileName[0].toStdString()).c_str());
	QMessageBox::information(this, "Imported Employees", QString("Employees have been succesfully imported:\nTotal Employees: ") + QString::number(count), QMessageBox::Ok);
	Update();
}

void GestordeViajes::exit() {
	QApplication::exit();
}

void GestordeViajes::employeeManagement() {
	EmployeeWindowClass *employeeWindow = new EmployeeWindowClass(this);
	employeeWindow->addManager(employeeManager);
	employeeWindow->linkPreviousWindow(this);
	employeeWindow->show();
	this->hide();
}
void GestordeViajes::travelManagement() {
	TravelWindowClass *window = new TravelWindowClass(this);
	window->addManager(travelManager);
	window->linkPreviousWindow(this);
	window->show();
	this->hide();
}