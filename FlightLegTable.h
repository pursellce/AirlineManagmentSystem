#ifndef FLIGHTLEG_H
#define FLIGHTLEG_H

#include <string>
#include <iostream>
#include <vector>
#include "structs.h"

using namespace std;
/*
class flightLegEntry{
	public:
	FlightLeg(string flno, string seq, string fromA="", string toA="", string depTime="", string arrTime="",string plane="");
	string FLNO;
	string seq;
	string fromA;
	string toA;
	string depTime;
	string arrTime;
	string plane;
};*/

class FlightLegTable{
	private:
	vector<flightLegEntry>* table;
	int tableSize;
	
	public:
	FlightLegTable(int);
	void Insert(flightLegEntry);
	void Update();
	void Select();
	void Delete();
	void Display();
	void Write();
	int Hash(flightLegEntry);
};
#endif