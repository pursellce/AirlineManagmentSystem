#include <iterator>
#include "FlightLegTable.h"

using namespace std;

FlightLegTable::FlightLegTable(int size)
{
	tableSize = size;
	table = new vector<flightLegEntry>[size];
}

void FlightLegTable::Display()
{
	cout<<"FLNO\tSeq\tFromA\tToA\tDeptTime\tArrTime\tPlane"<<endl;
	for(int i=0; i<tableSize; i++)
	{
		for(vector<flightLegEntry>::iterator it=table[i].begin(); it!= table[i].end(); it++)
		{
			cout<<(*it).flightNum<<"\t"<<(*it).sequence<<"\t"<<(*it).fromAirport<<"\t"<<(*it).toAirport<<"\t"<<(*it).depDate<<"\t"<<(*it).arvDate<<"\t"<<(*it).plane<<endl;
		}
	}
}

void FlightLegTable::Insert(flightLegEntry item)
{
	int index = Hash(item);
	table[index].push_back(item);
}

int FlightLegTable::Hash(flightLegEntry item)
{
	//Hashing function: Simple modulo hashing after multiplying the two parts of the key
	//and a prime number
	//Collision strategy: Chaining
	unsigned long long int total = 7;
	total = item.flightNum * item.sequence * 31;
	return total % tableSize;
}