#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_CreateTravelClass.h"
#include "TravelManager.h"
#include "TravelWindow.h"


class CreateTravelClass : public QDialog
{
	Q_OBJECT

public:
	CreateTravelClass(QWidget *parent = Q_NULLPTR);
	void linkPreviousWindow(TravelWindowClass *previous);
	void addManager(TravelManager* manager);

private:
	Ui::CreateTravelDialog ui;
	TravelWindowClass *previousWindow;
	TravelManager *manager;

private slots:
	void accept();
	void reject();
};

