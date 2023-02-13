#include <string>
#include <vector>
#include <iterator>
#include "FlightLegInstanceTable.h"

using namespace std;

FlightLegInstanceTable::FlightLegInstanceTable(int size)
{
	tableSize=size;
	table = new vector<flightLegInstanceEntry>[size];
}

void FlightLegInstanceTable::Display()
{
	cout<<"Seq\tFLNO\tFdate\tActDept\tActArr\tPilot"<<endl;
	for(int i=0; i<tableSize; i++)
	{
		for(vector<flightLegInstanceEntry>::iterator it=table[i].begin(); it!= table[i].end(); it++)
		{
			cout<<(*it).sequence<<"\t"<<(*it).flightNum<<(*it).flightDate<<(*it).depDate<<(*it).arvDate<<(*it).pilot<<endl;
		}
	}
}

void FlightLegInstanceTable::Insert(flightLegInstanceEntry item)
{
	int index = Hash(item);
	table[index].push_back(item);
}

int FlightLegInstanceTable::Hash(flightLegInstanceEntry item)
{
	unsigned long long int total = 7;
	//Hashing function: Simple modulo hashing after adding the three parts of the key together
	//Added in a prime number to multiply by for increased uniqueness
	//Collision strategy: Chaining
	for(int i=0; i<item.flightDate.size(); i++)
	{
		total = (item.flightNum + item.sequence) * 31 + item.flightDate[i];
	}
	return total % tableSize;
}