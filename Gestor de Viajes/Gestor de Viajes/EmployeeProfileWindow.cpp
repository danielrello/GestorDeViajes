#include "EmployeeProfileWindow.h"
#include <iostream>
#include "qmessagebox.h"


EmployeeProfileWindowClass::EmployeeProfileWindowClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Window
		| Qt::WindowMinimizeButtonHint
		| Qt::WindowMaximizeButtonHint);
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableWidget->setColumnCount(6);
	QStringList columnHeader;
	columnHeader << "ID" << "DepartureLocation" << "ArrivalLocation" << "DepartureTime" << "ArrivalTime" << "Cost";
	ui.tableWidget->setColumnHidden(0, true);
	ui.tableWidget->setHorizontalHeaderLabels(columnHeader);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	connect(ui.comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(linkTravel(QString)));
	connect(ui.backButton, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.tableWidget->selectionModel(), SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(changeTable(QItemSelection, QItemSelection)));

}

void EmployeeProfileWindowClass::linkPreviousWindow(EmployeeWindowClass * previous)
{
	previousWindow = previous;
}

void EmployeeProfileWindowClass::linkMainWindow(GestordeViajes * main)
{
	mainWindow = main;
	travelManager = mainWindow->getTravelManager();
	manager = mainWindow->getEmployeeManager();
}

void EmployeeProfileWindowClass::setEmployee(Employee * employee)
{
	this->employee = employee;

	QString resident = "Temporary Employee";
	if (employee->isResident()) {
		resident = "Resident Employee";
	}

	ui.nameOutput->setText(QString::fromStdString(employee->getName()));
	ui.surnameOutput->setText(QString::fromStdString(employee->getSurname()));
	ui.emailOutput->setText(QString::fromStdString(employee->getEmail()));
	ui.residentLabel->setText(resident);
	loadList();

	//Combo Box items

	ui.comboBox->addItem(QString(""), Qt::DisplayRole);
	for (auto i = 0; i < travelManager->getTravels().size(); i++) {
		Travel *travel = travelManager->getTravels()[i];
		string arrivalLocation = travel->getArrivalLocation();
		string departureLocation = travel->getDepartureLocation();
		string departureTime = travel->getDeparturetime();
		string arrivalTime = travel->getArrivalTime();
		int cost = travel->getCost();

		QString data =
			QString::number(travel->getID()) + QString(";") +
			QString::fromStdString(arrivalLocation) + QString(";") +
			QString::fromStdString(departureLocation) + QString(";") +
			QString::fromStdString(arrivalTime) + QString(";") +
			QString::fromStdString(departureTime) + QString(";") +
			QString::number(cost);
		ui.comboBox->addItem(data, Qt::DisplayRole);

	}
}

void EmployeeProfileWindowClass::addManager(EmployeeManager *manager)
{
	this->manager = manager;
}

void EmployeeProfileWindowClass::back() {
	previousWindow->show();
	this->hide();
}

void EmployeeProfileWindowClass::loadList() {
	Travel * travel;
	ui.tableWidget->setRowCount(0);
	Resident *employee = (Resident*)this->employee;
	if(employee->isResident())
		for (auto i = 0; i < employee->getTravels().size(); i++) {
			travel = employee->getTravels()[i];
			int row_number = ui.tableWidget->rowCount();
			ui.tableWidget->insertRow(row_number);

			QTableWidgetItem *id = new QTableWidgetItem;
			QTableWidgetItem *departureLocationItem = new QTableWidgetItem;
			QTableWidgetItem *arrivalLocationItem = new QTableWidgetItem;
			QTableWidgetItem *departureTimeItem = new QTableWidgetItem;
			QTableWidgetItem *arrivalTimeItem = new QTableWidgetItem;
			QTableWidgetItem *costItem = new QTableWidgetItem;

			int idNumber = travel->getID();
			string arrivalLocation = travel->getArrivalLocation();
			string departureLocation = travel->getDepartureLocation();
			string arrivalTime = travel->getArrivalTime();
			string departureTime = travel->getDeparturetime();
			int costNumber = travel->getCost();

			ui.tableWidget->setItem(row_number, 0, id);
			QString idString = QString::number(idNumber);
			id->setText(idString);
			ui.tableWidget->setItem(row_number, 1, departureLocationItem);
			departureLocationItem->setText(QString::fromStdString(departureLocation));
			ui.tableWidget->setItem(row_number, 2, arrivalLocationItem);
			arrivalLocationItem->setText(QString::fromStdString(arrivalLocation));
			ui.tableWidget->setItem(row_number, 3, departureTimeItem);
			departureTimeItem->setText(QString::fromStdString(departureTime));
			ui.tableWidget->setItem(row_number, 4, arrivalTimeItem);
			arrivalTimeItem->setText(QString::fromStdString(arrivalTime));
			ui.tableWidget->setItem(row_number, 5, costItem);
			QString cost = QString::number(costNumber);
			costItem->setText(cost);
		}
	else{
		ui.tableWidget->hide();
		ui.label_4->hide();
	}
}

void EmployeeProfileWindowClass::linkTravel(QString data)
{
	if (data != QString("")) {
		QStringList list;
		list = data.split(QString(";"));
		Resident* resident = (Resident*)employee;
		QString id = data[0];
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, "Modify Employee", QString("Do you want to link:\n")
			+ list[1] + QString(" | ") + list[2] + QString(" | ") + list[3] + QString(" | ") + list[4] + QString(" | ") + list[5],
			QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes) {
			resident->linkTravel(travelManager->getTravel(id.toInt()));
			loadList();
		}
		else {
			return;
		}
	}
}
