#include <string>
#include <iterator>
#include "FlightInstanceTable.h"

using namespace std;

FlightInstanceTable::FlightInstanceTable(int size)
{
	tableSize = size;
	table = new vector<flightInstanceEntry>[size];
}

void FlightInstanceTable::Display()
{
	cout<<"FLNO\tFdate"<<endl;
	for(int i=0; i<tableSize; i++)
	{
		for(vector<flightInstanceEntry>::iterator it=table[i].begin(); it!= table[i].end(); it++)
		{
			cout<<(*it).flightNum<<"\t"<<(*it).date<<endl;
		}
	}
}

void FlightInstanceTable::Insert(flightInstanceEntry item)
{
	int index = Hash(item);
	table[index].push_back(item);
}

int FlightInstanceTable::Hash(flightInstanceEntry item)
{
	//Hashing function: Simple modulo hashing after adding the ASCII value of the string and multiplying by a prime
	//Collision strategy: Chaining
	
	unsigned long long int total = 7;
	
	for(int i=0; i<item.date.size(); i++)
	{
		total = item.flightNum * 31 + item.date[i];
	}
	return total % tableSize;
}