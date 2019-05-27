#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EmployeeWindow.h"

class EmployeeWindowClass : public QMainWindow
{
	Q_OBJECT

public:
	EmployeeWindowClass(QWidget *parent = Q_NULLPTR);

private:
	Ui::EmployeeWindowClass ui;
private slots:
	void back(); 
	void loadList();
	void changeTable(const QItemSelection &selected, const QItemSelection &deselected);
};
