#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_EmployeeProfileWindow.h"
#include "EmployeeWindow.h"
#include "GestordeViajes.h"
#include "TravelManager.h"

class EmployeeProfileWindowClass : public QMainWindow
{
	Q_OBJECT

private:
	Ui::EmployeeProfileWindow ui;
	EmployeeManager *manager;
	TravelManager *travelManager;
	GestordeViajes *mainWindow;
	EmployeeWindowClass *previousWindow;
	Employee *employee;
public:
	EmployeeProfileWindowClass(QWidget *parent = Q_NULLPTR);
	void linkPreviousWindow(EmployeeWindowClass *previous);
	void linkMainWindow(GestordeViajes *main);
	void setEmployee(Employee *employee);
	void addManager(EmployeeManager *manager);
	void loadList();
private slots:
	void back();
	void linkTravel(QString data);
};
