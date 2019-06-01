#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_CreateEmployeeDialog.h"
#include "EmployeeManager.h"
#include "EmployeeWindow.h"


class CreateDialogClass : public QDialog
{
	Q_OBJECT

public:
	CreateDialogClass(QWidget *parent = Q_NULLPTR);
	void linkPreviousWindow(EmployeeWindowClass *previous);
	void addManager(EmployeeManager* manager);

private:
	Ui::CreateEmployeeDialog ui;
	EmployeeWindowClass *previousWindow;
	EmployeeManager *manager;

private slots:
	void adjustTextColor();
	void accept();
	void reject();
};

