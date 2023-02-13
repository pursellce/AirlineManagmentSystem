#ifndef PLANESEATS_H
#define PLANESEATS_H
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;
struct PlaneSeats {
		string make, model, seatType;
		int numSeats;
};

class PlaneSeatsTable{
	public:
		PlaneSeatsTable(int);
		vector<list<PlaneSeats>> planeSeatsTable;
		int tableSize;
		int hash(PlaneSeats planeSeats);
		void display();
		void insert(PlaneSeats planeSeats);
		/*
		void update(string, string);
		void select (string, string);
		void deleteEntry(string, string);
		void write ();*/
};

#endif