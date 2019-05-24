#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EmployeeManagement.h"

class EmployeeManagement : public QMainWindow
{
	Q_OBJECT

public:
	EmployeeManagement(QWidget *parent = Q_NULLPTR);

private:
	Ui::EmployeeManagementClass ui;
private slots:
	void back();
	void loadList();
	void handleMultipleSelectionInList(const QItemSelection& selection);
};
