#include "ModifyDialogClass.h"
#include "qmessagebox.h"
#include "ErrorHandler.h"

ModifyDialogClass::ModifyDialogClass(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.okButton, SIGNAL(accepted()), this, SLOT(accept()));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void ModifyDialogClass::linkPreviousWindow(EmployeeWindowClass * previous)
{
	this->previousWindow = previous;
}

void ModifyDialogClass::employeeData(Employee * employee)
{
	this->employee = employee;
	ui.nameInput->setText(QString::fromStdString(employee->getName()));
	ui.surnameInput->setText(QString::fromStdString(employee->getSurname()));
	ui.emailInput->setText(QString::fromStdString(employee->getEmail()));
}

void ModifyDialogClass::addManager(EmployeeManager * manager)
{
	this->manager = manager;
}

void ModifyDialogClass::reject()
{
	previousWindow->show();
	this->hide();
}

void ModifyDialogClass::accept()
{
	QString name = ui.nameInput->text();
	QString surname = ui.surnameInput->text();
	QString email = ui.emailInput->text();
	QRegularExpression error("\\W*");
	QRegularExpressionMatch match = error.match(name);
	if (match.hasMatch()) {
		errorDialog(this, CARACTER_ERROR);
		return;
	}
	match = error.match(surname);
	if (match.hasMatch()) {
		errorDialog(this, CARACTER_ERROR);
		return;
	}

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
