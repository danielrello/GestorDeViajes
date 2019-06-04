#include "EmailLoginDialog.h"
#include "ErrorHandler.h"

EmailLoginDialog::EmailLoginDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.okButton, SIGNAL(accepted()), this, SLOT(accept()));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void EmailLoginDialog::linkPreviousWindow(EmployeeProfileWindowClass * previous)
{
	previousWindow = previous;
}

void EmailLoginDialog::linkMainWindow(GestordeViajes * gestor)
{
	gestorViajes = gestor;
}

void EmailLoginDialog::reject()
{
	previousWindow->show();
	this->hide();
}

void EmailLoginDialog::accept()
{/*
	SMTPClientSession smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
	QString user = ui.userInput->text();
	QString password = ui.passwordInput->text();

	smtp.setUser(user);
	smtp.setPassword(password);

	smtp.connectToHost();
	if (smtp.login()) {
		gestorViajes->setUserAndPassword(user, password);
		this->hide();
		previousWindow->show();
	}
	else {
		errorDialog(this, LOGIN_ERROR);
	}*/
}
