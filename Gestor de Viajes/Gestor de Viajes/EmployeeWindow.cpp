#include "EmployeeWindow.h"
#include "GestordeViajes.h"
#include "EmployeeManager.h"
#include "qsqlquerymodel.h"
#include "qlistwidget.h"
#include "qstring.h"


EmployeeWindowClass::EmployeeWindowClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tableView->setSelectionMode(QAbstractItemView::ContiguousSelection);
	loadList();
	connect(ui.backButton, SIGNAL(clicked()), this, SLOT(back())); 
	connect(ui.tableView->selectionModel(), SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(changeTable(QItemSelection, QItemSelection)));
}

void EmployeeWindowClass::back() {
	GestordeViajes *gestorWindow = new GestordeViajes(this);
	gestorWindow->show();
	this->hide();
}

void EmployeeWindowClass::loadList() {
	QSqlQueryModel *model = new QSqlQueryModel();
	model->setQuery("SELECT name,surname,email FROM Resident");
	model->setHeaderData(0, Qt::Horizontal, tr("Name"));
	model->setHeaderData(1, Qt::Horizontal, tr("Surname"));
	model->setHeaderData(2, Qt::Horizontal, tr("Email"));
	ui.tableView->setModel(model);
}

void EmployeeWindowClass::changeTable(const QItemSelection & selected,
	const QItemSelection & deselected)
{
	QModelIndexList items = selected.indexes();
	QModelIndex index;
	if (items.size() > 0) {
		ui.modifyButton->setEnabled(true);
		ui.deleteButton->setEnabled(true);
	}
	else {
		ui.modifyButton->setEnabled(false);
		ui.deleteButton->setEnabled(false);

	}

	foreach(index, items) {
		QString text = index.data(Qt::DisplayRole).toString();
		//ui.selectedEmployeeL->setText(text);
	}
}
