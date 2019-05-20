#include "Database.h"

void setDataBase(QSqlDatabase *db)
{
	const QString DRIVER("QSQLITE");
	if (QSqlDatabase::isDriverAvailable(DRIVER))
		qWarning() << "Cargado modulo de bases de datos.";
	else
		qInfo() << "No se ha podido cargar el modulo de bases de datos.";


	*db = QSqlDatabase::addDatabase(DRIVER);
	db->setDatabaseName("database");

	if (!db->open())
		qDebug() << db->lastError().text();


	QSqlQuery query(
		"CREATE TABLE IF NOT EXISTS Resident ("
		"Id int not null default 0, "
		"name TEXT not null, "
		"surname TEXT not null, "
		"email TEXT not null, "
		"type int not null default 0,"
		"IdTravel INTEGER, "
		"PRIMARY KEY(Id), "
		"FOREIGN KEY(IdTravel) REFERENCES Travel(Id))"
	);
	if (!query.isActive())
		qWarning() << "CREATING ERROR: " << query.lastError().text();

	if(!query.exec(
		"CREATE TABLE IF NOT EXISTS Temporary ("
		"Id INTEGER not null default 0,"
		"name TEXT not null,"
		"surname TEXT not null,"
		"email TEXT not null,"
		"type int not null default 0,"
		"PRIMARY KEY(Id))"
	))		
		qWarning() << "CREATING ERROR: " << query.lastError().text();

	if(!query.exec(
		"CREATE TABLE IF NOT EXISTS Travel ("
		"Id INTEGER not null default 0,"
		"departureLocation TEXT,"
		"arrivalLocation TEXT,"
		"departureTime DATETIME,"
		"arrivalTime DATETIME,"
		"cost FLOAT,"
		"IdEmployee INTEGER,"
		"PRIMARY KEY(Id),"
		"FOREIGN KEY(IdEmployee) REFERENCES Resident(Id))"
	))
		qWarning() << "CREATING ERROR: " << query.lastError().text();

	//if (!query.exec("INSERT INTO resident(name, surname, email) VALUES('Eddie', 'Guerrero', 'eddiefasilon@gmail.com')"))
	//	qWarning() << "INSERTING ERROR: " << query.lastError().text();

	//query.prepare("SELECT name FROM resident");
	//if (!query.exec())
	//	qWarning() << "SELECTING ERROR: " << query.lastError().text();
	//if (query.first())
	//	qInfo() << query.value(0).toString();
}

void insertQuery(char **data, int source)
{
	QSqlQuery query;
	switch (source)
	{
	case RESIDENT:
		query.prepare("INSERT INTO resident(id, name, surname, email, type) VALUES(:param1, :param2, :param3, :param4, :param5)");
		break;
	case TEMPORARY:
		query.prepare("INSERT INTO temporary(id, name, surname, email, type) VALUES(:param1, :param2, :param3, :param4, :param5)");
		break;
	case TRAVEL:
		query.prepare(
			"INSERT INTO travel(id, departurelocation, arrivallocation, departuretime, arrivaltime, cost)"
			"VALUES(:param1, :param2, :param3, :param4, :param5, , :param6)");
		break;
	}
	query.bindValue(":param1", data[0]);
	query.bindValue(":param2", data[1]);
	query.bindValue(":param3", data[2]);
	query.bindValue(":param4", source);
	if(source != TRAVEL)
		query.bindValue(":param5", source);
	if (source == TRAVEL) {
		query.bindValue(":param5", data[4]);
		query.bindValue(":param6", data[5]);
	}
	if (!query.exec())
		qWarning() << "INSERTING ERROR: " << query.lastError().text();
}

void selectQuery(char **data, int source)
{
	QSqlQuery query("SELECT name, surname FROM resident");
	if (query.first())
		qInfo() << query.value(0).toString() << query.value(1).toString();
}

void deleteQuery(char * data, int source)
{
	QSqlQuery query("DELETE FROM resident");
	if (!query.exec())
		qWarning() << "DELETING ERROR: " << query.lastError().text();
}
