#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "plane.h"

using namespace std;
		
		int PlaneTable::hash(Plane plane){
			int key;
			int table_size = 23;
			key = (plane.ID % table_size);
			return key;
		}

		void PlaneTable::insert(Plane plane){
			planeTable[hash(plane)].push_back(plane);
		}
		

		void PlaneTable::display(){
			cout<<"Plane Table"<<endl;
			cout<<"ID\t Make\t Model\t Last Maintence\t Last Maintence Airport\n";
			for (int i=0; i < planeTable.size(); i++){  //traverse the indexes
				for (Plane j : planeTable[i]){
					cout<<j.ID<<"\t"<<j.make<<"\t"<<j.model<<"\t"<<j.lastMaint<<"\t"<<j.lastMaintAirport<<endl;
				}
			}
		}

		PlaneTable::PlaneTable(int size)
		{
			tableSize = size;
			planeTable.resize(size);
		}

		/*
		void update(string, string);
		void select (string, string);
		void deleteEntry(string, string);
		void write ();
		*/