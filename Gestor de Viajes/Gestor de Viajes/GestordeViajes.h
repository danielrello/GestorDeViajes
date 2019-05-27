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
	TravelManager *travelManager;
	EmployeeManager *employeeManager;

private:
	Ui::GestordeViajesClass ui;
private slots:
	void employeeManagement();
	void exit();
};
