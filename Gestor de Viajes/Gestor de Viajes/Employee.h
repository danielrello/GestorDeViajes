#pragma once
#include <iostream>
#include <string>

#define MAXLENGHT 50

class Employee
{
protected:
	int id;
	std::string email, name, surname;
	virtual void print();
public:
	int getID();
	std::string getEmail();
	std::string getName();
	std::string getSurname();
	void setID(int id);
	void setEmail(std::string email);
	void setName(std::string name);
	void setSurname(std::string surname);
	virtual bool isResident() { return false; }
	void Update();
	Employee();
	Employee(std::string name, std::string surname, std::string email, int id);
	~Employee();
};

