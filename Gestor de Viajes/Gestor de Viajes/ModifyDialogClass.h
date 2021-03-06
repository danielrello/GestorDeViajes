#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_ModifyEmployeeDialog.h"
#include "EmployeeManager.h"
#include "EmployeeWindow.h"


class ModifyDialogClass : public QDialog
{
	Q_OBJECT

public:
	ModifyDialogClass(QWidget *parent = Q_NULLPTR);
	void linkPreviousWindow(EmployeeWindowClass *previous);
	void employeeData(Employee *employee);
	void addManager(EmployeeManager* manager);

private:
	Ui::ModifyEmployeeDialog ui;
	EmployeeWindowClass *previousWindow;
	Employee *employee;
	EmployeeManager *manager;

private slots:
	void accept();
	void reject();
};

