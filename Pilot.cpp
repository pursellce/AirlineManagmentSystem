#include "Pilot.h"
#include <list>
#include <iostream>
#include <string>

using namespace std;

	
	int hashpilot::Hash(pilot key){ // gets location
			return key.ID % bucket;
	} 

	void hashpilot::Insert(pilot key){ // The put it where it goes
		//get location
		int loc = Hash(key);

		//go to lcation and push the value in this case key
		table[loc].push_back(key);
	}
	
	//bool pilot::Delete(pilot key){}// The get rid of it

	//bool pilot::Search(pilot key){}// The find it

	void hashpilot::Display(){ // The visualizer
		//iterator fot list
		list<pilot>::iterator i;
		cout<<"ID\tName\tDateHired"<<endl;
		//For function to iterate through the array
		for (int j = 0; j < bucket; j++) {
			//lable the line
			//cout << j << ": ";

			//Print the line
			for (i = table[j].begin(); i != table[j].end(); i++)
			{
				cout << "( " << i->ID << " , " << i->name << " , " << i->dateHired << " ) -> ";
				cout << endl;
			}
			//end the line
		}

		//The pretty end printing seperation
		cout << endl;
	}
	