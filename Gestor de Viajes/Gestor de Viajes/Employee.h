#pragma once
#include <iostream>
#include <string>
class Employee
{
protected:
	int id;
	std::string email, name, surname;
	virtual bool isResident() {};
public:
	int getID();
	std::string getEmail();
	std::string getName();
	std::string getSurname();
	void setID(int id);
	void setEmail(std::string email);
	void setName(std::string name);
	void setSurname(std::string surname);
	Employee();
	Employee(std::string name, std::string surname, std::string email, int id);
	~Employee();
};

