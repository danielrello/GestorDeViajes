#include "Employee.h"
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlDriver>
#include <Qtsql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QtSql/qsqlrecord.h>
#include <qdebug.h>

using namespace std;

void Employee::Update()
{
	char *type = new char[10];
	char **data = (char**)malloc(sizeof(char*) * 3);

	for (int i = 0; i < 3; i++) {
		data[i] = (char*)malloc(sizeof(char) * MAXLENGHT);
	}

	if (isResident()) {
		type = "resident";
	}
	else {
		type = "temporary";
	}

	char opcion;

	cout << "Data Base Update with changes:" << endl;
	print();
	QSqlQuery query;
	//Paso los datos a un vector de chars
	name.copy(data[0], name.size());
	data[0][name.size()] = '\0';
	surname.copy(data[1], surname.size());
	data[1][surname.size()] = '\0';
	email.copy(data[2], email.size());
	data[2][email.size()] = '\0';

#pragma region Delete
	//Compruebo si estamos eliminando un empleado, si tienen todo igual, estamos borrando.	
	query.prepare(QString(
		"SELECT id, name, surname, email "
		"FROM %1 "
		"WHERE id=%2 AND name='%3' AND surname='%4' AND EMAIL='%5'")
		.arg(type)
		.arg(id)
		.arg(data[0])
		.arg(data[1])
		.arg(data[2]));
	if (!query.exec()) {
		qDebug() << "SELECT ERROR: " << query.lastError().text();
	}
	if (query.first()) {
		qDebug() << "Eliminando: " << query.value(0).toInt() << " | " << query.value(1).toString().toUtf8() << " | " << query.value(2).toString().toUtf8();
		query.prepare(QString(
			"DELETE FROM %1 "
			"WHERE id=%2")
			.arg(type)
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
		"FROM %1 "
		"WHERE id=%2").arg(type).arg(id));
	if (!query.exec())
		qDebug() << query.lastError();
	if (query.first()) {
		query.prepare(QString(
			"UPDATE %5 "
			"SET name='%1', surname='%2', email='%3' "
			"WHERE id=%4")
			.arg(data[0])
			.arg(data[1])
			.arg(data[2])
			.arg(id)
			.arg(type));
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
		"SELECT name, surname, email, COUNT(*) "
		"FROM %1 "
		"GROUP BY name, surname, email "
		"HAVING COUNT(*) >= 1").arg(type));
	if (!query.exec())
		qDebug() << query.lastError();
	if (query.first()) {
		cout << "Usuario duplicado: Desea continuar? (Y/N)" << endl;
		cin >> opcion;
		if (opcion == 'N' || opcion == 'n') {
			return;
		}
	}
	cout << "Insertando..." << endl;
	//Añado el residente a la base de datos
	query.prepare(QString(
		"INSERT INTO %1(id, name, surname, email) VALUES(:param1, :param2, :param3, :param4)")
		.arg(type));
	query.bindValue(":param1", id);
	query.bindValue(":param2", data[0]);
	query.bindValue(":param3", data[1]);
	query.bindValue(":param4", data[2]);
	if (!query.exec()) {
		qDebug() << "Insert Error: " << query.lastError();
	}
#pragma endregion

}

Employee::Employee()
{
	id = 0;
}

Employee::Employee(std::string name, std::string surname, std::string email, int id)
{
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->id = id;
}


Employee::~Employee()
{
}

void Employee::print()
{
	std::cout << id << " | " << name << " | " << surname << " | "<< email << std::endl;
}

int Employee::getID()
{
	return id;
}

std::string Employee::getEmail()
{
	return email;
}

std::string Employee::getName()
{
	return name;
}

std::string Employee::getSurname()
{
	return surname;
}

void Employee::setID(int id)
{
	this->id = id;
}

void Employee::setEmail(std::string email)
{
	this->email = email;
}

void Employee::setName(std::string name)
{
	this->name = name;
}

void Employee::setSurname(std::string surname)
{
	this->surname = surname;
}
