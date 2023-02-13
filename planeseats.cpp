#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "planeseats.h"

using namespace std;
		int PlaneSeatsTable::hash(PlaneSeats planeSeats){
			int key, sum=0;
			int table_size = 23;
			sum+=planeSeats.make[0];
			sum+=planeSeats.make[1];
			sum+=planeSeats.model[0];
			sum+=planeSeats.model[1];
			key = sum % table_size;
			return key;
		}
		
		void PlaneSeatsTable::insert(PlaneSeats planeSeats){
			planeSeatsTable[hash(planeSeats)].push_back(planeSeats);
		}
		
		void PlaneSeatsTable::display(){
			cout<<"Plane Seats Table"<<endl;
			cout<<"Make\t Model\t Seat Type\t Number of Seats\n";
			for (int i=0; i < planeSeatsTable.size(); i++){  //traverse the indexes
				for (PlaneSeats j : planeSeatsTable[i]){
					cout<<j.make<<"\t"<<j.model<<"\t"<<j.seatType<<"\t\t"<<j.numSeats<<endl;
				}
			}
		}					
		
		PlaneSeatsTable::PlaneSeatsTable(int size)
		{
			tableSize = size;
			planeSeatsTable.resize(size);
		}