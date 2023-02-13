#ifndef PILOTH
#define PILOTH

#include <list>
#include <iostream>
#include <string>

using namespace std;

struct pilot{
	int ID;
	string name;
	string dateHired;
};


class hashpilot {
private:
	//Storage 
	int bucket = 0; 
	list<pilot>* table;
	
public:

	hashpilot(){ //The set up
		bucket = 23;
		table = new list<pilot>[bucket];
	}

	int Hash(pilot key); // gets location

	void Insert(pilot key);// The put it where it goes

	bool Delete(pilot key);// The get rid of it

	bool Search(pilot key);// The find it

	void Display();// The visualizer
	

};

#endif

