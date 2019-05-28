#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EmployeeWindow.h"
#include "GestordeViajes.h"
#include "EmployeeManager.h"

class EmployeeWindowClass : public QMainWindow
{
	Q_OBJECT

private:
	Ui::EmployeeWindowClass ui;
	EmployeeManager *manager;
	Employee *selectedEmployee;
	GestordeViajes *previousWindow;
public:
	EmployeeWindowClass(QWidget *parent = Q_NULLPTR);
	void linkPreviousWindow(GestordeViajes *previous);
	void addManager(EmployeeManager *manager);
	void loadList();
private slots:
	void back(); 
	void changeTable(const QItemSelection &selected, const QItemSelection &deselected);
	void loadEmployee(const QModelIndex & selected);
	void modifyEmployee();
	void deleteEmployee();
	void addEmployee();
	void addTravel();
};
