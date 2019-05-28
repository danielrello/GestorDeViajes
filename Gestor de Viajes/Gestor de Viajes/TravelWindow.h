#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TravelWindow.h"
#include "GestordeViajes.h"
#include "EmployeeManager.h"

class TravelWindowClass : public QMainWindow
{
	Q_OBJECT

private:
	Ui::TravelWindowClass ui;
	TravelManager *travelManager;
	Travel *selectedTravel;
	GestordeViajes *previousWindow;
public:
	TravelWindowClass(QWidget *parent = Q_NULLPTR);
	void linkPreviousWindow(GestordeViajes *previous);
	void addManager(TravelManager *manager);
	void loadList();
private slots:
	void back(); 
	void changeTable(const QItemSelection &selected, const QItemSelection &deselected);
	void loadTravel(const QModelIndex & selected);
	void modifyTravel();
	void deleteTravel();
	void addTravel();
};
