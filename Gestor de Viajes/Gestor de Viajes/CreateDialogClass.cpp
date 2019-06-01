#include "CreateDialogClass.h"
#include "ErrorHandler.h"
#include "qmessagebox.h"

CreateDialogClass::CreateDialogClass(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.mailError->hide(); 

	QRegularExpression error("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b", QRegularExpression::CaseInsensitiveOption);
	ui.emailInput->setValidator(new QRegularExpressionValidator(error, this));	
	connect(ui.emailInput, SIGNAL(textChanged(QString)), this, SLOT(adjustTextColor()));
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

void CreateDialogClass::adjustTextColor() {
	if (!ui.emailInput->hasAcceptableInput()) {
		ui.mailError->show();
		ui.mailError->setText(QString("You must insert a valid mail."));
		ui.emailInput->setStyleSheet("QLineEdit { color: red;}");
	}
	else {
		ui.mailError->hide();
		ui.emailInput->setStyleSheet("QLineEdit { color: black;}");
	}
}

void CreateDialogClass::accept()
{
	QString name = ui.nameInput->text();
	QString surname = ui.surnameInput->text();
	QString email = ui.emailInput->text();
	QRegularExpression error("*\\W*");
	if (error.match(name).hasMatch()) {
		errorDialog(this, CARACTER_ERROR);
		return;
	}
	if (error.match(surname).hasMatch()) {
		errorDialog(this, CARACTER_ERROR);
		return;
	}
	if (!ui.mailError->isHidden()) {
		errorDialog(this, FORMAT_ERROR);
		return;

	}


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