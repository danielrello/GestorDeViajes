#pragma once
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlDriver>
#include <Qtsql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QtSql/qsqlrecord.h>
#include <qdebug.h>
#include "EmployeeManager.h"
#include "TravelManager.h"

#define TEMPORARY 0
#define RESIDENT 1
#define TRAVEL 2

void setDataBase(QSqlDatabase *db);
void readDataBase(EmployeeManager *manage0r, TravelManager *travelManager);