#ifndef AIRPORTH
#define AIRPORTH

#include <list>
#include <iostream>
#include <string>

using namespace std;

struct airport{
	string code;
	string city;
	string state;
};


class hashAirport {
private:
	//Storage 
	int bucket = 0; 
	list<airport>* table;
	
public:

	hashAirport(int);

	int Hash(airport key); // gets location

	void Insert(airport key);// The put it where it goes

	bool Delete(airport key);// The get rid of it

	bool Search(airport key);// The find it

	void Display();// The visualizer
	

};

#endif