#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GestordeViajes.h"
#include "EmployeeManager.h"
#include "TravelManager.h"

class GestordeViajes : public QMainWindow
{
	Q_OBJECT

public:
	GestordeViajes(QWidget *parent = Q_NULLPTR);
	void addManagers(TravelManager *travelManager, EmployeeManager *employeeManager);
	TravelManager* getTravelManager();
	EmployeeManager* getEmployeeManager();
	void Update();

private:
	TravelManager *travelManager;
	EmployeeManager *employeeManager;
	Ui::GestordeViajesClass ui;
private slots:
	void employeeManagement();
	void travelManagement();
	void importTravels();
	void importEmployees();
	void exit();
};
