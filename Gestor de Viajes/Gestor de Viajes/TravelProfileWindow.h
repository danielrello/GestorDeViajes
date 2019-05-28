#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_TravelProfileWindow.h"
#include "TravelWindow.h"
#include "GestordeViajes.h"
#include "TravelManager.h"

class TravelProfileWindowClass : public QMainWindow
{
	Q_OBJECT

private:
	Ui::TravelProfileWindow ui;
	TravelManager *travelManager;
	GestordeViajes *mainWindow;
	TravelWindowClass *previousWindow;
	Travel *travel;
public:
	TravelProfileWindowClass(QWidget *parent = Q_NULLPTR);
	void linkPreviousWindow(TravelWindowClass *previous);
	void linkMainWindow(GestordeViajes *main);
	void setTravel(Travel *travel);
	void addManager(TravelManager *manager);
private slots:
	void back();
};
