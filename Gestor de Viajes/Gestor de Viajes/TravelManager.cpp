#include "TravelManager.h"

using namespace std;


int TravelManager::getPos(int id)
{
	int pos = -1 ;
	for (int i = 0; i < travels.size(); i++) {
		if (travels[i]->getID() == id) {
			pos = i;
		}
	}
	return pos;
}

TravelManager::TravelManager()
{
	loadingDataBase = true;
	lastID = -1;
}


TravelManager::~TravelManager()
{
}

void TravelManager::setLoading(bool loading)
{
	loadingDataBase = loading;
}

Travel * TravelManager::getTravel(int id)
{
	Travel * travel = nullptr;
	int pos = getPos(id);
	if (pos != -1) {
		travel = travels[pos];
	}
	return travel;
}

void TravelManager::addTravel(int id, std::string departureLocation, std::string arrivalLocation, std::string departureTime, std::string arrivalTime, int cost)
{
	Travel *travel = new Travel(id, departureLocation, arrivalLocation, departureTime, arrivalTime, cost);
	travels.emplace_back(travel);
	if (!loadingDataBase)
		travel->Update();
	lastID = id;
}

void TravelManager::editTravel(int id, std::string departureLocation, std::string arrivalLocation, std::string departureTime, std::string arrivalTime, int cost)
{
	if (getTravel(id) == nullptr) {
		cout << "The travel with id: " << id << " does not exist." << endl;
	}
	else {
		getTravel(id)->setArrivalLocation(arrivalLocation);
		getTravel(id)->setDepartureLocation(departureLocation);
		getTravel(id)->setArrivalTime(arrivalTime);
		getTravel(id)->setDepartureTime(departureTime);
		getTravel(id)->setCost(cost);
		getTravel(id)->Update();
	}
}

void TravelManager::deleteTravel(int id)
{
	int posToDelete = getPos(id);
	if (posToDelete != -1) {
		cout << "PosToDelete: " << posToDelete << endl;
		getTravel(id)->Update();
		travels.erase(travels.begin() + (posToDelete));
	}
	else {
		cout << "The travel with id: " << id << " does not exist." << endl;
	}
}

int TravelManager::getLastID()
{
	return lastID;
}


std::vector<Travel*> TravelManager::getTravels()
{
	return travels;
}
