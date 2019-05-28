#include "ModifyTravelClass.h"
#include "qmessagebox.h"

ModifyTravelClass::ModifyTravelClass(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.okButton, SIGNAL(accepted()), this, SLOT(accept()));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void ModifyTravelClass::linkPreviousWindow(TravelWindowClass * previous)
{
	this->previousWindow = previous;
}

void ModifyTravelClass::travelData(Travel * travel)
{
	this->travel = travel;

	QDateTime departure = QDateTime::fromString(QString::fromStdString(travel->getDeparturetime()), QString("yyyy/mm/dd HH:mm"));
	QDateTime arrival = QDateTime::fromString(QString::fromStdString(travel->getArrivalTime()), QString("yyyy/mm/dd HH:mm"));;

	ui.departureLocation->setText(QString::fromStdString(travel->getDepartureLocation()));
	ui.arrivalLocation->setText(QString::fromStdString(travel->getArrivalLocation()));
	ui.departureTime->setDateTime(departure);
	ui.arrivalTime->setDateTime(arrival);
	ui.costInput->setText(QString::number (travel->getCost()));
}

void ModifyTravelClass::addManager(TravelManager * manager)
{
	this->manager = manager;
}

void ModifyTravelClass::reject()
{
	previousWindow->show();
	this->hide();
}

void ModifyTravelClass::accept()
{
	QString departureLocation = ui.departureLocation->text();
	QString arrivalLocation = ui.arrivalLocation->text();
	QString departureTime = ui.departureTime->text();
	QString arrivalTime = ui.arrivalTime->text();
	int cost = ui.costInput->text().toInt();

	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Modify Travel", "Do you want to confirm the changes?",
		QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) {
		manager->editTravel(travel->getID(), departureLocation.toStdString(), arrivalLocation.toStdString(), departureTime.toStdString(), arrivalTime.toStdString(), cost);
		previousWindow->loadList();
		previousWindow->show();
		this->hide();
	}
	else {
		qDebug() << "Yes was *not* clicked";
		this->show();
	}

}
