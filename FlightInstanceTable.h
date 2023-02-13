#ifndef FLIGHTINSTANCE_H
#define FLIGHTINSTANCE_H

#include <string>
#include <iostream>
#include <vector>
#include "structs.h"

using namespace std;

struct FlightInstance{
	string FLNO;
	string FDate;
};

class FlightInstanceTable{
	private:
	vector<flightInstanceEntry>* table;
	int tableSize;
	
	public:
	FlightInstanceTable(int);
	void Insert(flightInstanceEntry);
	void Update();
	void Select();
	void Delete();
	void Display();
	void Write();
	int Hash(flightInstanceEntry);
};

#endif