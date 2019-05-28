#include "CreateDialogClass.h"
#include "qmessagebox.h"

CreateDialogClass::CreateDialogClass(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.okButton, SIGNAL(accepted()), this, SLOT(accept()));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void CreateDialogClass::linkPreviousWindow(EmployeeWindowClass * previous)
{
	this->previousWindow = previous;
}

void CreateDialogClass::addManager(EmployeeManager * manager)
{
	this->manager = manager;
}

void CreateDialogClass::reject()
{
	previousWindow->show();
	this->hide();
}

void CreateDialogClass::accept()
{
	QString name = ui.nameInput->text();
	QString surname = ui.surnameInput->text();
	QString email = ui.emailInput->text();

	int lastID = manager->getLastID() + 1;
	bool isResident = ui.isResidentCBox->isChecked();

	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Create Employee", "Do you want to confirm the changes?",
		QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) {
		manager->addEmployee(isResident, lastID, name.toStdString(), surname.toStdString(), email.toStdString());
		previousWindow->loadList();
		previousWindow->show();
		this->hide();
		return;
	}
	else {
		qDebug() << "Yes was *not* clicked";
		this->show();
		return;
	}

}