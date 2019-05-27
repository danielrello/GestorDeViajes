#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_ModifyEmployeeDialog.h"
#include "EmployeeManager.h"


class ModifyDialogClass : QDialog
{
	Q_OBJECT

public:
	ModifyDialogClass(QWidget *parent = Q_NULLPTR);

private:
	Ui::ModifyEmployeeDialog ui;
private slots:
	void accept();
	void reject();
};

