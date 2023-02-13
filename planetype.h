#ifndef PLANETYPE_H
#define PLANETYPE_H
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <list>

using namespace std;

struct PlaneType {

		string make, model;
		int flySpeed, groundSpeed;
};

class PlaneTypeTable{
	public:
		PlaneTypeTable(int);
		int tableSize;
		vector<list<PlaneType>> planeTypeTable;
		int hash(PlaneType planeType);
		void display();
		void insert(PlaneType planeType);
		/*
		void update(string, string);
		void select (string, string);
		void deleteEntry(string, string);
		void write ();
		*/
};

#endif