#pragma once
#include "Employee.h"
class Travel
{
protected:
	int id;
	std::string departureLocation, arrivalLocation;
	std::string departureTime, arrivalTime;
	int cost;
public:
	int getID();
	std::string getDepartureLocation();
	std::string getArrivalLocation();
	std::string getDeparturetime();
	std::string getArrivalTime();
	int getCost();

	void setID(int id);
	void setDepartureLocation(std::string departure);
	void setArrivalLocation(std::string arrival);
	void setDepartureTime(std::string departure);
	void setArrivalTime(std::string arrival);
	void setCost(int cost);
	void linkEmployee(Employee* employee);

	void Update();
	void print();
	Travel();
	Travel(int id, std::string departureLocation, std::string arrivalLocation, std::string departureTime, std::string arrivalTime, int cost);
	~Travel();
};

