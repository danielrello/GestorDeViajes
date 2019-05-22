#include "Database.h"

using namespace std;

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
}

void readDataBase(EmployeeManager *manager)
{
	vector<string> data;

	qWarning() << "Leyendo base de datos...";
	QSqlQuery query("SELECT * FROM resident");
	QSqlRecord rec = query.record();
	qDebug() << "Number of columns: " << rec.count();
	int nameCol = rec.indexOf("name");
	int id;
	while (query.next()) {
		for (int i = 0; i < rec.count() - 1; i++) {
			if (i == 0)
				id = query.value(1).toInt();
			else {
				string readedData = query.value(i).toString().toUtf8();
				data.emplace_back(readedData);
			}
		}
		manager->addEmployee(1, id, data[0], data[1], data[2]);
		data.erase(data.begin(), data.end());
	}
	query.prepare("SELECT * FROM temporary");
	qDebug() << "Number of columns: " << rec.count();
	while (query.next()) {
		for (int i = 0; i < rec.count() - 1; i++) {
			if (i == 0)
				id = query.value(1).toInt();
			else {
				string readedData = query.value(i).toString().toUtf8();
				data.emplace_back(readedData);
			}
		}
		manager->addEmployee(0, id, data[0], data[1], data[2]);
	}
	manager->setLoading(false);
}

void selectQuery(char **data, int source)
{
	QSqlQuery query("SELECT name, surname FROM resident");
	while (query.next())
		qInfo() << query.value(0).toString() << query.value(1).toString();
}

void deleteQuery(char * data, int source)
{
	QSqlQuery query("DELETE FROM resident, temporary WHERE id=:param1");
	query.bindValue(":param1", data);
	if (!query.exec())
		qWarning() << "DELETING ERROR: " << query.lastError().text();
}
