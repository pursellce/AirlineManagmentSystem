//text
#include "Airport.h"
#include <list>
#include <iostream>
#include <string>

hashAirport::hashAirport(int size) { //The set up
		bucket = size;
		table = new list<airport>[bucket];
	}

int hashAirport::Hash(airport key){	 // gets location
	//The real hash
	int sum = 0;
	sum += key.code.at(0);
	sum += key.code.at(1);
	sum += key.code.at(2);
	return sum % bucket;
	
}

void hashAirport::Insert(airport key){ // The put it where it goes
	
	//get location
	int loc = Hash(key);

	//go to lcation and push the value in this case key
	table[loc].push_back(key);
	
}

bool hashAirport::Delete(airport key){// The get rid of it
	
}

bool hashAirport::Search(airport key){// The find it
	
	
}

void hashAirport::Display(){// The visualizer
	
	//iterator fot list

	cout<<"Code\tCity\tState"<<endl;
	//For function to iterate through the array
	for (int j = 0; j < bucket; j++){
		//lable the line
		//Print the line
		for (list<airport>::iterator i = table[j].begin(); i != table[j].end(); i++)
		{
			cout << "( " << i->code << " , " << i->city << " , " << i->state << " ) -> ";
			cout << endl;
		}
		//end the line
	}

	//The pretty end printing seperation
	cout << endl;
	
}