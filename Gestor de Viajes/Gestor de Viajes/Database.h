#pragma once
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlDriver>
#include <Qtsql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <qdebug.h>

#define RESIDENT 0
#define TEMPORARY 1
#define TRAVEL 2

void setDataBase(QSqlDatabase *db);
void insertQuery(char **data, int source);
void selectQuery(char **data, int source);
void deleteQuery(char *data, int source);