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
	void setUserAndPassword(QString user, QString password);
	QStringList getUserAndPassword();
	void Update();

private:
	TravelManager *travelManager;
	EmployeeManager *employeeManager;
	Ui::GestordeViajesClass ui;
	QString userLogin;
	QString passwordLogin;
private slots:
	void employeeManagement();
	void travelManagement();
	void importTravels();
	void importEmployees();
	void exit();
};
