#include "TravelManager.h"
#include <fstream>
#include <sstream>

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

void TravelManager::importTravels(const char* filePath)
{
	fstream file;
	file.open(filePath, ios::in);
	if (!file.is_open()) {
		cout << "No se puedo abrir el archivo." << endl;
		return;
	}
	int count = 0;

	vector<vector<string>> info;
	string line;
	while (getline(file, line))                   // read a whole line of the file
	{
		stringstream ss(line);
		string data;                // put it in a stringstream (internal stream)
		vector<string>row;

		row.clear();

		while (getline(ss, data, ';'))           // read (string) items up to a semmicolon
		{
			row.push_back(data);
		}
		count++;
		if (row.size() == 5) info.push_back(row);
		else {
			cout << "Se ha descartado la línea " << count << " por falta de argumentos" << endl;
		}// add non-empty rows to matrix   // add non-empty rows to matrix
	}
	for (int i = 1; i < info.size(); i++) {
		addTravel(lastID + 1, info[i][0], info[i][1], info[i][2], info[i][3], stoi(info[i][4]));
	}

	if (count == 0)
		cout << "Empty CSV\n";
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

void TravelManager::setLastID(int id)
{
	lastID = id;
}


std::vector<Travel*> TravelManager::getTravels()
{
	return travels;
}
