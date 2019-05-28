#include "LinkDialogClass.h"
#include "qmessagebox.h"

LinkDialogClass::LinkDialogClass(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.okButton, SIGNAL(accepted()), this, SLOT(accept()));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void LinkDialogClass::linkPreviousWindow(EmployeeWindowClass * previous)
{
	this->previousWindow = previous;
}

void LinkDialogClass::employeeData(Employee * employee)
{
	this->employee = employee;
	ui.nameOutput->setText(QString::fromStdString(employee->getName()));
	ui.surnameOutput->setText(QString::fromStdString(employee->getSurname()));
	ui.emailOutput->setText(QString::fromStdString(employee->getEmail()));
}

void LinkDialogClass::addManager(EmployeeManager * manager, TravelManager* travel)
{
	this->manager = manager;
	this->travelManager = travel;
}

void LinkDialogClass::reject()
{
	previousWindow->show();
	this->hide();
}

void LinkDialogClass::accept()
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Modify Employee", "Do you want to confirm the changes?",
		QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) {
		manager->editEmployee(employee->getID(), name.toStdString(), surname.toStdString(), email.toStdString());
		previousWindow->loadList();
		previousWindow->show();
		this->hide();
	}
	else {
		qDebug() << "Yes was *not* clicked";
		this->show();
	}

}
