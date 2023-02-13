#ifndef FLIGHTLEGINSTANCE_H
#define FLIGHTLEGINSTANCE_H

#include <string>
#include <iostream>
#include <vector>
#include "structs.h"

using namespace std;

struct FlightLegInstance{
	string seq;
	string FLNO;
	string FDate;
	string actDept;
	string actArr;
	string pilot;
};

class FlightLegInstanceTable {
	private:
	vector<flightLegInstanceEntry>* table;
	int tableSize;
	
	public:
	FlightLegInstanceTable(int);
	void Insert(flightLegInstanceEntry);
	void Update();
	void Select();
	void Delete();
	void Display();
	void Write();
	int Hash(flightLegInstanceEntry);
};

#endif