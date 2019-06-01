#pragma once
#include "qmessagebox.h"
#define FORMAT_ERROR 0
#define NUMBER_ERROR 1
#define LOGIN_ERROR 2
#define DUPLICATED_ERROR 3
#define DUPLICATED_ARRIVALDEPARTURE_ERROR 4
#define DB_ERROR 5
#define CARACTER_ERROR 6
#define EMPLOYEE_LIMIT_ERROR 7
#define PDF_ERROR 8
#define MAIL_SERVICE_ERROR 9

int errorDialog(QWidget *widget, int typeError);