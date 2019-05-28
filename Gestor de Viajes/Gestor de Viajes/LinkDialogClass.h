#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_LinkTravelDialog.h"
#include "EmployeeManager.h"
#include "TravelManager.h"
#include "EmployeeWindow.h"


class LinkDialogClass : public QDialog
{
	Q_OBJECT

public:
	LinkDialogClass(QWidget *parent = Q_NULLPTR);
	void linkPreviousWindow(EmployeeWindowClass *previous);
	void employeeData(Employee *employee);
	void addManager(EmployeeManager* manager, TravelManager* travel);

private:
	Ui::LinkTravelDialog ui;
	EmployeeWindowClass *previousWindow;
	Employee *employee;
	EmployeeManager *manager;
	TravelManager *travelManager;

private slots:
	void accept();
	void reject();
};

