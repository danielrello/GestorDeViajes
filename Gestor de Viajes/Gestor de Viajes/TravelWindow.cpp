
#include <iostream>
#include "TravelWindow.h"
#include "GestordeViajes.h"
#include "qstring.h"
#include "qmessagebox.h"
#include "ModifyTravelClass.h"
#include "CreateTravelClass.h"
#include "TravelProfileWindow.h"

TravelWindowClass::TravelWindowClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableWidget->setColumnCount(6);
	QStringList columnHeader;
	columnHeader << "ID" << "DepartureLocation" << "ArrivalLocation" << "DepartureTime" << "ArrivalTime" << "Cost";
	ui.tableWidget->setColumnHidden(0, true);
	ui.tableWidget->setHorizontalHeaderLabels(columnHeader);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	connect(ui.backButton, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.modifyButton, SIGNAL(clicked()), this, SLOT(modifyTravel()));
	connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(deleteTravel()));
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addTravel()));
	connect(ui.tableWidget->selectionModel(), SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(changeTable(QItemSelection, QItemSelection)));
	connect(ui.tableWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(loadTravel(QModelIndex)));
}

void TravelWindowClass::linkPreviousWindow(GestordeViajes * previous)
{
	previousWindow = previous;
}

void TravelWindowClass::addManager(TravelManager *manager)
{
	this->travelManager = manager;
	loadList();
}

void TravelWindowClass::back() {
	previousWindow->Update();
	previousWindow->show();
	this->hide();
}

void TravelWindowClass::loadList() {
	Travel * travel;
	ui.tableWidget->setRowCount(0);
	for (auto i = 0; i < travelManager->getTravels().size(); i++) {
		travel = travelManager->getTravels()[i];
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
}

void TravelWindowClass::loadTravel(const QModelIndex & selected)
{
	int selectedRow = selected.row();
	QTableWidgetItem *itemId = ui.tableWidget->item(selectedRow, 0);

	Travel *travel = travelManager->getTravel(itemId->text().toInt());
	TravelProfileWindowClass *window = new TravelProfileWindowClass;

	window->linkPreviousWindow(this);
	window->linkMainWindow(previousWindow);
	window->setTravel(travel);
	window->show();
}

void TravelWindowClass::modifyTravel()
{
		ModifyTravelClass *modifyWindow = new ModifyTravelClass(this);
		modifyWindow->linkPreviousWindow(this);
		modifyWindow->addManager(travelManager);
		modifyWindow->travelData(selectedTravel);
		modifyWindow->show();
		this->hide();
}

void TravelWindowClass::addTravel()
{
	CreateTravelClass *createWindow = new CreateTravelClass(this);
	createWindow->linkPreviousWindow(this);
	createWindow->addManager(travelManager);
	createWindow->show();
	this->hide();
}

void TravelWindowClass::deleteTravel()
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Delete Travel", "Do you want to delete this travel?\n"
		+ QString::fromStdString(selectedTravel->getDepartureLocation()) + "-"
		+ QString::fromStdString(selectedTravel->getArrivalLocation()) + " | "
		+ QString::fromStdString(selectedTravel->getDeparturetime()) + " | "
		+ QString::fromStdString(selectedTravel->getArrivalTime()) + " | "
		+ QString::number(selectedTravel->getCost()) + " | "
		,
		QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) {
		travelManager->deleteTravel(selectedTravel->getID());
		loadList();
	}
	else {
		qDebug() << "Yes was *not* clicked";
	}
}

void TravelWindowClass::changeTable(const QItemSelection & selected, const QItemSelection & deselected)
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
		//ui.employeeLabel->setText(text);
		selectedTravel = travelManager->getTravel((ui.tableWidget->item(selectedRow, 0)->text()).toInt());
	}
}