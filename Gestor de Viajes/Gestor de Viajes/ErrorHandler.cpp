#include "ErrorHandler.h"

int errorDialog(QWidget *widget, int typeError)
{
	int response = 0;
	QString title;
	QString text;
	QMessageBox::StandardButton warning;
	switch (typeError)
	{
	case FORMAT_ERROR:
		title = "Format error";
		text = "We could not resolve the information provided.";
		break;
	case DUPLICATED_ERROR:
		title = "Duplicated Error";
		text = "We detected another employee with the same name and surname.\nDo you want to continue?";
		break;
	case LOGIN_ERROR:
		title = "Login Error";
		text = "User or password may be incorrect";
		break;
	case DUPLICATED_ARRIVALDEPARTURE_ERROR:
		title = "Duplicated Error";
		text = "Departure and arrival location can't be the same";
		break;
	case DB_ERROR:
		title = "Database Error";
		text = "We could not access de database information.";
		break;
	case NUMBER_ERROR:
		title = "Number Error";
		text = "Caracter inserted must be a number.";
		break;
	case CARACTER_ERROR:
		title = "Caracter Error";
		text = "Caracter inserted not correct.";
		break;
	case EMPLOYEE_LIMIT_ERROR:
		title = "Employee Limit";
		text = "You cant add more employees to this travel.";
		break;
	case PDF_ERROR:
		title = "PDF Error";
		text = "We could not export the employee data.";
		break;
	case MAIL_SERVICE_ERROR:
		title = "Email Error";
		text = "We could not connect to Email service.\nPlease check your internet connection.";
		break;

	default:
		break;
	}
	if (typeError > 5)
		warning = QMessageBox::warning(widget, title, text, QMessageBox::Ok);
	else {
		warning = QMessageBox::information(widget, title, text, QMessageBox::Yes, QMessageBox::No);
		if (warning = QMessageBox::Yes) {
			response = QMessageBox::Yes;
		}
		else
			response = QMessageBox::No;
	}
	return response;
}
