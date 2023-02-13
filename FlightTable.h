#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include "structs.h"

using namespace std;

class FlightTable{
	private:
	vector<flightEntry>* table;
	int tableSize;
	
	public:
	FlightTable(int);
	void Insert(flightEntry);
	void Update();
	void Select();
	void Delete();
	void Display();
	void Write();
	int Hash(flightEntry);
};

#endif