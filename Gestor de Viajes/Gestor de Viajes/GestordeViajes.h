#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GestordeViajes.h"

class GestordeViajes : public QMainWindow
{
	Q_OBJECT

public:
	GestordeViajes(QWidget *parent = Q_NULLPTR);

private:
	Ui::GestordeViajesClass ui;
};
