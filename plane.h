#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

struct Plane {
		int ID;
		string make, model, lastMaint, lastMaintAirport;
		
};

class PlaneTable{
	public:
		PlaneTable(int);
		int tableSize;
		vector<list<Plane>> planeTable;
		int hash(Plane plane);
		void insert(Plane plane);
		void display();
		
		/*
		
		void update(string, string);
		void select (string, string);
		void deleteEntry(string, string);
		void write ();
		*/
};

#endif