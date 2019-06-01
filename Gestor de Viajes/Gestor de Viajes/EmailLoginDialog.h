#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_EmailLoginDialog.h"
#include "EmployeeProfileWindow.h"
#include "GestordeViajes.h"

class EmailLoginDialog : public QDialog
{
	Q_OBJECT
private:
	Ui::emailLoginDialog ui;
	EmployeeProfileWindowClass *previousWindow;
	GestordeViajes *gestorViajes;
public:
	EmailLoginDialog(QWidget *parent = Q_NULLPTR);
	void linkPreviousWindow(EmployeeProfileWindowClass *previous);
	void linkMainWindow(GestordeViajes *gestor);

private slots:
	void accept();
	void reject();
};

