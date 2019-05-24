#include "EmployeeManagement.h"
#include "GestordeViajes.h"
#include "EmployeeManager.h"
#include "qsqlquerymodel.h"
#include "qlistwidget.h"
#include "qstring.h"


EmployeeManagement::EmployeeManagement(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	connect(ui.backButton, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.tableView, SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(handleMultipleSelectionInList(QItemSelection)));

	loadList();
}

void EmployeeManagement::back() {
	GestordeViajes *gestorWindow = new GestordeViajes(this);
	gestorWindow->show();
	this->hide();
}

void EmployeeManagement::loadList() {
	QSqlQueryModel *model = new QSqlQueryModel();
	model->setQuery("SELECT name,surname FROM Resident");
	model->setHeaderData(0, Qt::Horizontal, tr("Name"));
	model->setHeaderData(1, Qt::Horizontal, tr("Surname"));
	ui.tableView->setModel(model);
}

void EmployeeManagement::handleMultipleSelectionInList(const QItemSelection& selection) {
	
}
