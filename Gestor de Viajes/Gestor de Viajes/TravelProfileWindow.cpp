#include "TravelProfileWindow.h"
#include <iostream>
#include "qmessagebox.h"


TravelProfileWindowClass::TravelProfileWindowClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Window
		| Qt::WindowMinimizeButtonHint
		| Qt::WindowMaximizeButtonHint);

	connect(ui.backButton, SIGNAL(clicked()), this, SLOT(back()));
}

void TravelProfileWindowClass::linkPreviousWindow(TravelWindowClass * previous)
{
	previousWindow = previous;
}

void TravelProfileWindowClass::linkMainWindow(GestordeViajes * main)
{
	mainWindow = main;
	travelManager = mainWindow->getTravelManager();
	travelManager = mainWindow->getTravelManager();
}

void TravelProfileWindowClass::setTravel(Travel * travel)
{
	this->travel = travel;
	ui.departureLocation->setText(QString::fromStdString(travel->getDepartureLocation()));
	ui.arrivalLocation->setText(QString::fromStdString(travel->getArrivalLocation()));
	ui.departureTime->setText(QString::fromStdString(travel->getDeparturetime()));
	ui.arrivalTime->setText(QString::fromStdString(travel->getArrivalTime()));
	ui.cost->setText(QString::number(travel->getCost()));
}

void TravelProfileWindowClass::addManager(TravelManager *manager)
{
	this->travelManager = manager;
}

void TravelProfileWindowClass::back() {
	previousWindow->show();
	this->hide();
}