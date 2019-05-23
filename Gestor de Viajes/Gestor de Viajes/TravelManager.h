#pragma once
#include "Travel.h"
#include <vector>

class TravelManager
{
	std::vector<Travel*> travels;
	int lastID;
	bool loadingDataBase;
	int getPos(int id);
public:
	TravelManager();
	~TravelManager();
	void importTravels();
	void setLoading(bool loading);
	Travel* getTravel(int id);
	void addTravel(int id, std::string departureLocation, std::string arrivalLocation, std::string departureTime, std::string arrivalTime, int cost);
	void editTravel(int id, std::string departureLocation, std::string arrivalLocation, std::string departureTime, std::string arrivalTime, int cost);
	void deleteTravel(int id);
	int getLastID();
	std::vector<Travel*> getTravels();
};

