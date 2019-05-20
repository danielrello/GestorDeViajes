#include "Employee.h"



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
