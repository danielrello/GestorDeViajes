#include "EmployeeProfileWindow.h"
#include <iostream>
#include "qmessagebox.h"
#include "qfiledialog.h"
#include "qtextdocument.h"
#include "qprinter.h"
#include "EmailLoginDialog.h"
#include "ErrorHandler.h"

EmployeeProfileWindowClass::EmployeeProfileWindowClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Window
		| Qt::WindowMinimizeButtonHint
		| Qt::WindowMaximizeButtonHint);
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableWidget->setColumnCount(6);
	QStringList columnHeader;
	columnHeader << "ID" << "DepartureLocation" << "ArrivalLocation" << "DepartureTime" << "ArrivalTime" << "Cost";
	ui.tableWidget->setColumnHidden(0, true);
	ui.tableWidget->setHorizontalHeaderLabels(columnHeader);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//connect(ui.sendMailButton, SIGNAL(clicked()), SLOT(sendMail()));
	connect(ui.comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(linkTravel(QString)));
	connect(ui.backButton, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.tableWidget->selectionModel(), SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(changeTable(QItemSelection, QItemSelection)));
	connect(ui.exportButton, SIGNAL(clicked()), SLOT(exportToPDF()));
}

void EmployeeProfileWindowClass::linkPreviousWindow(EmployeeWindowClass * previous)
{
	previousWindow = previous;
}

void EmployeeProfileWindowClass::linkMainWindow(GestordeViajes * main)
{
	mainWindow = main;
	travelManager = mainWindow->getTravelManager();
	manager = mainWindow->getEmployeeManager();
}

void EmployeeProfileWindowClass::setEmployee(Employee * employee)
{
	this->employee = employee;

	QString resident = "Temporary Employee";
	if (employee->isResident()) {
		resident = "Resident Employee";
	}

	ui.nameOutput->setText(QString::fromStdString(employee->getName()));
	ui.surnameOutput->setText(QString::fromStdString(employee->getSurname()));
	ui.emailOutput->setText(QString::fromStdString(employee->getEmail()));
	ui.residentLabel->setText(resident);
	loadList();

	//Combo Box items
	if (employee->isResident()) {
		ui.comboBox->addItem(QString(""), Qt::DisplayRole);
		for (auto i = 0; i < travelManager->getTravels().size(); i++) {
			Travel *travel = travelManager->getTravels()[i];
			string arrivalLocation = travel->getArrivalLocation();
			string departureLocation = travel->getDepartureLocation();
			string departureTime = travel->getDeparturetime();
			string arrivalTime = travel->getArrivalTime();
			int cost = travel->getCost();

			QString data =
				QString::number(travel->getID()) + QString(";") +
				QString::fromStdString(arrivalLocation) + QString(";") +
				QString::fromStdString(departureLocation) + QString(";") +
				QString::fromStdString(arrivalTime) + QString(";") +
				QString::fromStdString(departureTime) + QString(";") +
				QString::number(cost);
			ui.comboBox->addItem(data, Qt::DisplayRole);

		}
	}
	else {
		ui.comboBox->hide();
		ui.label_5->hide();
	}
}

void EmployeeProfileWindowClass::addManager(EmployeeManager *manager)
{
	this->manager = manager;
}

void EmployeeProfileWindowClass::back() {
	this->hide();
	previousWindow->show();
}

void EmployeeProfileWindowClass::loadList() {
	Travel * travel;
	ui.tableWidget->setRowCount(0);
	Resident *employee = (Resident*)this->employee;
	if(employee->isResident())
		for (auto i = 0; i < employee->getTravels().size(); i++) {
			travel = employee->getTravels()[i];
			int row_number = ui.tableWidget->rowCount();
			ui.tableWidget->insertRow(row_number);

			QTableWidgetItem *id = new QTableWidgetItem;
			QTableWidgetItem *departureLocationItem = new QTableWidgetItem;
			QTableWidgetItem *arrivalLocationItem = new QTableWidgetItem;
			QTableWidgetItem *departureTimeItem = new QTableWidgetItem;
			QTableWidgetItem *arrivalTimeItem = new QTableWidgetItem;
			QTableWidgetItem *costItem = new QTableWidgetItem;

			int idNumber = travel->getID();
			string arrivalLocation = travel->getArrivalLocation();
			string departureLocation = travel->getDepartureLocation();
			string arrivalTime = travel->getArrivalTime();
			string departureTime = travel->getDeparturetime();
			int costNumber = travel->getCost();

			ui.tableWidget->setItem(row_number, 0, id);
			QString idString = QString::number(idNumber);
			id->setText(idString);
			ui.tableWidget->setItem(row_number, 1, departureLocationItem);
			departureLocationItem->setText(QString::fromStdString(departureLocation));
			ui.tableWidget->setItem(row_number, 2, arrivalLocationItem);
			arrivalLocationItem->setText(QString::fromStdString(arrivalLocation));
			ui.tableWidget->setItem(row_number, 3, departureTimeItem);
			departureTimeItem->setText(QString::fromStdString(departureTime));
			ui.tableWidget->setItem(row_number, 4, arrivalTimeItem);
			arrivalTimeItem->setText(QString::fromStdString(arrivalTime));
			ui.tableWidget->setItem(row_number, 5, costItem);
			QString cost = QString::number(costNumber);
			costItem->setText(cost);
		}
	else{
		ui.tableWidget->hide();
		ui.label_4->hide();
	}
}

void EmployeeProfileWindowClass::sendMail()
{
	//EmailLoginDialog login;
	//login.linkPreviousWindow(this);
	//login.linkMainWindow(mainWindow);

	//SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
	//QStringList credentials = mainWindow->getUserAndPassword();

	//smtp.setUser(credentials[0]);
	//smtp.setPassword(credentials[1]);

	//MimeMessage message;

	//message.setSender(new EmailAddress(credentials[0], "Gestor de Viajes"));
	//message.addRecipient(new EmailAddress(QString::fromStdString(employee->getEmail()), QString::fromStdString(employee->getName())));
	//message.setSubject("Recordatorio de viaje");

	//// Now add some text to the email.
	//// First we create a MimeText object.

	//MimeText text;

	//Resident* resident = (Resident*)employee;
	//QString infoViajes;
	//for (int i = 0; i < resident->getTravels().size(); i++) {
	//	QString departureLocation = QString::fromStdString(resident->getTravels()[i]->getDepartureLocation());
	//	QString arrivalLocation = QString::fromStdString(resident->getTravels()[i]->getArrivalLocation());
	//	QString departureTime = QString::fromStdString(resident->getTravels()[i]->getDeparturetime());
	//	QString arrivalTime = QString::fromStdString(resident->getTravels()[i]->getArrivalTime());
	//	QString cost = QString::number(resident->getTravels()[i]->getCost());

	//	infoViajes +=
	//		QString("\n---------------------------------------------\nViaje %1 - %2\n").arg(departureLocation).arg(arrivalLocation) +
	//		QString("Hora de Salida: %1\nHora de llegada: %2\n").arg(departureTime).arg(arrivalTime) +
	//		QString("Coste del viaje: %1").arg(cost) + 
	//		QString("---------------------------------------------\n");
	//}

	//text.setText(
	//	QString("Querido %1 %2:\nTe adjunto los viajes que tienes pendientes.\n")
	//	.arg(QString::fromStdString(resident->getName()))
	//	.arg(QString::fromStdString(resident->getSurname()))
	//	+ infoViajes
	//);

	//// Now add it to the mail

	//message.addPart(&text);

	//smtp.connectToHost();
	//if (smtp.login()) {
	//	if (!smtp.sendMail(message)) {
	//		errorDialog(this, MAIL_SERVICE_ERROR);
	//	}
	//	else
	//		smtp.quit();
	//}
	//else {
	//	errorDialog(this, LOGIN_ERROR);
	//}
}

void EmployeeProfileWindowClass::exportToPDF()
{
	QFileDialog saveDialog;
	QString fileName = saveDialog.getSaveFileName((QWidget*)0, "Export PDF", QString(), "*.pdf");
	if (!QFileInfo(fileName).baseName().isEmpty()) {
		if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
		QPrinter printer(QPrinter::PrinterResolution);
		printer.setOutputFormat(QPrinter::PdfFormat);
		printer.setPaperSize(QPrinter::A4);
		printer.setOutputFileName(fileName);
		Resident* resident = (Resident*)employee;
		QString infoViajes;
		for (int i = 0; i < resident->getTravels().size(); i++) {
			QString departureLocation = QString::fromStdString(resident->getTravels()[i]->getDepartureLocation());
			QString arrivalLocation = QString::fromStdString(resident->getTravels()[i]->getArrivalLocation());
			QString departureTime = QString::fromStdString(resident->getTravels()[i]->getDeparturetime());
			QString arrivalTime = QString::fromStdString(resident->getTravels()[i]->getArrivalTime());
			QString cost = QString::number(resident->getTravels()[i]->getCost());

			infoViajes +=
				QString("<h2>Viaje %1 - %2</h2>").arg(departureLocation).arg(arrivalLocation) +
				QString("<p>Hora de Salida: %1</p><p>Hora de llegada: %2</p>").arg(departureTime).arg(arrivalTime) +
				QString("<p>Coste del viaje: %1</p>").arg(cost);
		}

		QTextDocument doc;
		doc.setHtml(
			QString("<h1>Ficha de empleado</h1><p>Nombre: %1\</p><p>Apellido: %2</p><p>Email: %3</p>")
			.arg(QString::fromStdString(employee->getName()))
			.arg(QString::fromStdString(employee->getSurname()))
			.arg(QString::fromStdString(employee->getEmail())) + infoViajes
		);
		doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
		doc.print(&printer);
	}
}

void EmployeeProfileWindowClass::linkTravel(QString data)
{
	if (data != QString("")) {
		QStringList list;
		list = data.split(QString(";"));
		Resident* resident = (Resident*)employee;
		QString id = data[0];
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, "Modify Employee", QString("Do you want to link:\n")
			+ list[1] + QString(" | ") + list[2] + QString(" | ") + list[3] + QString(" | ") + list[4] + QString(" | ") + list[5],
			QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes) {
			resident->linkTravel(travelManager->getTravel(id.toInt()));
			loadList();
		}
		else {
			return;
		}
	}
}
