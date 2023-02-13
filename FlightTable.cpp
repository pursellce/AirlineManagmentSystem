#include "FlightTable.h"
#include <iostream>
#include <string>
using namespace std;

FlightTable::FlightTable(int size)
{
	tableSize= size;
	table = new vector<flightEntry>[size];
}

void FlightTable::Display()
{
	cout<<"FLNO\tMeal\tSmoking"<<endl;
	for(int i=0; i<tableSize; i++)
	{
		for(vector<flightEntry>::iterator it=table[i].begin(); it!= table[i].end(); it++)
		{
			cout<<(*it).flightNum<<"\t"<<(*it).meal<<(*it).smoking<<endl;
		}
	}
}

void FlightTable::Insert(flightEntry item)
{
	int index = Hash(item);
	table[index].push_back(item);
}

int FlightTable::Hash(flightEntry item)
{
	//Hashing function: Simple modulo hashing after multiplying by a prime for uniqueness
	//Collision strategy: Chaining
	int total = 7;
	total = total * item.flightNum;
	return total % tableSize;
}