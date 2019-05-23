#include "Travel.h"
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlDriver>
#include <Qtsql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QtSql/qsqlrecord.h>
#include <qdebug.h>

using namespace std;

int Travel::getID()
{
	return id;
}

std::string Travel::getDepartureLocation()
{
	return departureLocation;
}

std::string Travel::getArrivalLocation()
{
	return arrivalLocation;
}

std::string Travel::getDeparturetime()
{
	return departureTime;
}

std::string Travel::getArrivalTime()
{
	return arrivalTime;
}

int Travel::getCost()
{
	return cost;
}

void Travel::setID(int id)
{
	this->id = id;
}

void Travel::setDepartureLocation(std::string departure)
{
	departureLocation = departure;
}

void Travel::setArrivalLocation(std::string arrival)
{
	arrivalLocation = arrival;
}

void Travel::setDepartureTime(std::string departure)
{
	departureTime = departure;
}

void Travel::setArrivalTime(std::string arrival)
{
	arrivalTime = arrival;
}

void Travel::setCost(int cost)
{
	this->cost = cost;
}

void Travel::Update()
{
	char **data = (char**)malloc(sizeof(char*) * 3);

	for (int i = 0; i < 5; i++) {
		data[i] = (char*)malloc(sizeof(char) * MAXLENGHT);
	}

	char opcion;

	cout << "Data Base Update with changes:" << endl;
	print();
	QSqlQuery query;
	//Paso los datos a un vector de chars
	departureLocation.copy(data[0], departureLocation.size());
	data[0][departureLocation.size()] = '\0';
	arrivalLocation.copy(data[1], arrivalLocation.size());
	data[1][arrivalLocation.size()] = '\0';
	departureTime.copy(data[2], departureTime.size());
	data[2][departureTime.size()] = '\0';
	arrivalTime.copy(data[3], arrivalTime.size());
	data[3][arrivalTime.size()] = '\0';

#pragma region Delete
	//Compruebo si estamos eliminando un empleado, si tienen todo igual, estamos borrando.	
	query.prepare(QString(
		"SELECT id, departureLocation, arrivalLocation, departureTime, arrivalTime, cost "
		"FROM travel "
		"WHERE id=%2 AND departureLocation='%3' AND arrivalLocation='%4' AND departureTime='%5' AND arrivalTime='%6' AND cost=%7")
		.arg(id)
		.arg(data[0])
		.arg(data[1])
		.arg(data[2])
		.arg(data[3])
		.arg(cost));
	if (!query.exec()) {
		qDebug() << "SELECT ERROR: " << query.lastError().text();
	}
	if (query.first()) {
		qDebug() << "Eliminando: " << query.value(0).toInt() << " | " << query.value(1).toString().toUtf8() << " | " << query.value(2).toString().toUtf8();
		query.prepare(QString(
			"DELETE FROM travel "
			"WHERE id=%2")
			.arg(id));
		if (!query.exec())
			qDebug() << "DELETE ERROR: " << query.lastError().text() << endl;
		return;
	}
#pragma endregion


#pragma region Modify
	//Compruebo si estamos insertando un nuevo empleado o modificando otro, si tienen mismo id, estamos modificando.	
	query.prepare(QString(
		"SELECT id "
		"FROM travel "
		"WHERE id=%2").arg(id));
	if (!query.exec())
		qDebug() << "SELECT ERROR: "<< query.lastError().text();
	if (query.first()) {
		query.prepare(QString(
			"UPDATE travel "
			"SET departureLocation='%1', arrivalLocation='%2', departureTime='%3', arrivalTime='%4', cost=%5 "
			"WHERE id=%4")
			.arg(data[0])
			.arg(data[1])
			.arg(data[2])
			.arg(data[3])
			.arg(cost)
			.arg(id));
		if (!query.exec()) {
			qDebug() << "ERROR: " << query.lastError().text();
			return;
		}
		else {
			cout << "Modificando..." << endl;
			return;
		}
	}
#pragma endregion

#pragma region Insert
	//Compruebo que el residente no esta duplicado
	query.prepare(QString(
		"SELECT departureLocation, arrivalLocation, departureTime, arrivalTime, COUNT(*) "
		"FROM travel "
		"GROUP BY departureLocation, arrivalLocation, departureTime, arrivalTime "
		"HAVING COUNT(*) >= 1"));
	if (!query.exec())
		qDebug() << "SELECT ERROR: " << query.lastError().text();
	if (query.first()) {
		cout << "Travel duplicated: Continue? (Y/N)" << endl;
		cin >> opcion;
		if (opcion == 'N' || opcion == 'n') {
			return;
		}
	}
	cout << "Insertando..." << endl;
	//Añado el residente a la base de datos
	query.prepare(QString(
		"INSERT INTO travel(id, departureLocation, arrivalLocation, departureTime, arrivalTime, cost) "
		"VALUES(:param1, :param2, :param3, '%1', '%2', :param4)").arg(data[2]).arg(data[3]));
	query.bindValue(":param1", id);
	query.bindValue(":param2", data[0]);
	query.bindValue(":param3", data[1]);
	query.bindValue(":param4", cost);
	if (!query.exec()) {
		qDebug() << "INSERT ERROR: " << query.lastError().text();
	}
#pragma endregion

}

void Travel::print()
{
	std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Flight number: " << id << " | " << departureLocation << "-" << arrivalLocation << std::endl;
	std::cout << "Departure Time:" << departureTime << std::endl;
	std::cout << "Arrival Time:" << arrivalTime << std::endl;
	std::cout << "Flight cost:" << cost << std::endl;
	std::cout << "---------------------------------------------------------------------------------------------" << std::endl;

}

Travel::Travel()
{
}

Travel::Travel(int id, std::string departureLocation, std::string arrivalLocation, std::string departureTime, std::string arrivalTime, int cost)
{
	this->id = id;
	this->departureLocation = departureLocation;
	this->arrivalLocation = arrivalLocation;
	this->departureTime = departureTime;
	this->arrivalTime = arrivalTime;
	this->cost = cost;
}

