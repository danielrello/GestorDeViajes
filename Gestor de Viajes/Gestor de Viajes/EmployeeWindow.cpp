
#include <iostream>
#include "EmployeeWindow.h"
#include "GestordeViajes.h"
#include "qstring.h"
#include "ModifyDialogClass.h"
#include "CreateDialogClass.h"
#include "EmployeeProfileWindow.h"
#include "qmessagebox.h"


EmployeeWindowClass::EmployeeWindowClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableWidget->setColumnCount(5);
	QStringList columnHeader;
	columnHeader << "ID" << "Type" << "Name" << "Surname" << "Email";
	ui.tableWidget->setColumnHidden(0, true);
	ui.tableWidget->setHorizontalHeaderLabels(columnHeader);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	connect(ui.backButton, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.modifyButton, SIGNAL(clicked()), this, SLOT(modifyEmployee()));
	connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(deleteEmployee()));
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addEmployee()));
	connect(ui.addTravelButton, SIGNAL(clicked()), this, SLOT(addTravel()));
	connect(ui.tableWidget->selectionModel(), SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(changeTable(QItemSelection, QItemSelection)));
	connect(ui.tableWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(loadEmployee(QModelIndex)));
}

void EmployeeWindowClass::linkPreviousWindow(GestordeViajes * previous)
{
	previousWindow = previous;
}

void EmployeeWindowClass::addManager(EmployeeManager *manager)
{
	this->manager = manager;
	loadList();
}

void EmployeeWindowClass::back() {
	previousWindow->Update();
	previousWindow->show();
	this->hide();
}

void EmployeeWindowClass::loadList() {
	Employee * employee;
	ui.tableWidget->setRowCount(0);
	for (auto i = 0; i < manager->getEmployees().size(); i++) {
		employee = manager->getEmployees()[i];
		int row_number = ui.tableWidget->rowCount();
		ui.tableWidget->insertRow(row_number);

		QTableWidgetItem *id = new QTableWidgetItem;
		QTableWidgetItem *typeItem = new QTableWidgetItem;
		QTableWidgetItem *nameItem = new QTableWidgetItem;
		QTableWidgetItem *surnameItem = new QTableWidgetItem;
		QTableWidgetItem *emailItem = new QTableWidgetItem;

		int idNumber = employee->getID();
		bool isResident = employee->isResident();
		string type;
		if (isResident)
			type = "Resident";
		else
			type = "Temporary";

		string name = employee->getName();
		string surname = employee->getSurname();
		string email = employee->getEmail();

		ui.tableWidget->setItem(row_number, 0, id);
		QString idString = QString::number(idNumber);
		id->setText(idString);
		ui.tableWidget->setItem(row_number, 1, typeItem);
		typeItem->setText(QString::fromStdString(type));
		ui.tableWidget->setItem(row_number, 2, nameItem);
		nameItem->setText(QString::fromStdString(name));
		ui.tableWidget->setItem(row_number, 3, surnameItem);
		surnameItem->setText(QString::fromStdString(surname));
		ui.tableWidget->setItem(row_number, 4, emailItem);
		emailItem->setText(QString::fromStdString(email));
	}
}

void EmployeeWindowClass::loadEmployee(const QModelIndex & selected)
{
	int selectedRow = selected.row();
	QTableWidgetItem *itemId = ui.tableWidget->item(selectedRow, 0);

	Employee *employee = manager->getEmployee(itemId->text().toInt());
	EmployeeProfileWindowClass *window = new EmployeeProfileWindowClass;

	window->linkPreviousWindow(this);
	window->linkMainWindow(previousWindow);
	window->setEmployee(employee);
	window->show();
}

void EmployeeWindowClass::modifyEmployee()
{
		ModifyDialogClass *modifyWindow = new ModifyDialogClass(this);
		modifyWindow->linkPreviousWindow(this);
		modifyWindow->addManager(manager);
		modifyWindow->employeeData(selectedEmployee);
		modifyWindow->show();
		this->hide();
}

void EmployeeWindowClass::addEmployee()
{
	CreateDialogClass *createWindow = new CreateDialogClass(this);
	createWindow->linkPreviousWindow(this);
	createWindow->addManager(manager);
	createWindow->show();
	this->hide();
}

void EmployeeWindowClass::addTravel()
{
}

void EmployeeWindowClass::deleteEmployee()
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Delete Employee", "Do you want to delete this employee?\n"
		+ QString::fromStdString(selectedEmployee->getName()) + " | "
		+ QString::fromStdString(selectedEmployee->getSurname()) + " | "
		+ QString::fromStdString(selectedEmployee->getEmail()) + " | "
		,
		QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) {
		manager->deleteEmployee(selectedEmployee->getID());
		loadList();
	}
	else {
		qDebug() << "Yes was *not* clicked";
	}
}

void EmployeeWindowClass::changeTable(const QItemSelection & selected, const QItemSelection & deselected)
{
	QModelIndexList items = selected.indexes();
	QModelIndex index;
	if (items.size() > 0) {
		ui.modifyButton->setEnabled(true);
		ui.deleteButton->setEnabled(true);
	}
	else {
		ui.modifyButton->setEnabled(false);
		ui.deleteButton->setEnabled(false);
	}

	foreach(index, items) {
		QString text = index.data(Qt::DisplayRole).toString();
		int selectedRow = index.row();
		if (manager->getEmployee((ui.tableWidget->item(selectedRow, 0)->text()).toInt())->isResident()) {
			ui.addTravelButton->setEnabled(true);
		}
		else {
			ui.addTravelButton->setEnabled(false);
		}
		//ui.employeeLabel->setText(text);
		selectedEmployee = manager->getEmployee((ui.tableWidget->item(selectedRow, 0)->text()).toInt());
	}
}