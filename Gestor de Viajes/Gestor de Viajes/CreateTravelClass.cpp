#include "CreateTravelClass.h"
#include "qmessagebox.h"
#include "ErrorHandler.h"

CreateTravelClass::CreateTravelClass(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.okButton, SIGNAL(accepted()), this, SLOT(accept()));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void CreateTravelClass::linkPreviousWindow(TravelWindowClass * previous)
{
	this->previousWindow = previous;
}

void CreateTravelClass::addManager(TravelManager * manager)
{
	this->manager = manager;
}

void CreateTravelClass::reject()
{
	previousWindow->show();
	this->hide();
}

void CreateTravelClass::accept()
{
	QString departureLocation = ui.departureLocation->text();
	QString arrivalLocation = ui.arrivalLocation->text();
	QString departureTime = ui.departureTime->text();
	QString arrivalTime = ui.arrivalTime->text();
	QString cost = ui.costInput->text();

	QRegularExpression error("\\W*");
	QRegularExpressionMatch match = error.match(departureLocation);
	if (arrivalLocation == departureLocation) {
		errorDialog(this, DUPLICATED_ARRIVALDEPARTURE_ERROR);
		return;
	}
	if (match.hasMatch()) {
		errorDialog(this, CARACTER_ERROR);
		return;
	}
	match = error.match(arrivalLocation);
	if (match.hasMatch()) {
		errorDialog(this, CARACTER_ERROR);
		return;
	}
	error.setPattern("\\D*");
	match = error.match(cost);
	if (match.hasMatch()) {
		errorDialog(this, NUMBER_ERROR);
		return;
	}

	int lastID = manager->getLastID() + 1;

	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Create Employee", "Do you want to confirm the changes?",
		QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) {
		manager->addTravel(lastID, departureLocation.toStdString(), arrivalLocation.toStdString(), departureTime.toStdString(), arrivalTime.toStdString(), cost.toInt());
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