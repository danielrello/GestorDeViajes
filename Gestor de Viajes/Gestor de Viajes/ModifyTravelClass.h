#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_ModifyTravelDialog.h"
#include "TravelManager.h"
#include "TravelWindow.h"


class ModifyTravelClass : public QDialog
{
	Q_OBJECT

public:
	ModifyTravelClass(QWidget *parent = Q_NULLPTR);
	void linkPreviousWindow(TravelWindowClass *previous);
	void travelData(Travel *travel);
	void addManager(TravelManager* manager);

private:
	Ui::ModifyTravelDialog ui;
	TravelWindowClass *previousWindow;
	Travel *travel;
	TravelManager *manager;

private slots:
	void accept();
	void reject();
};

