#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "planetype.h"

using namespace std;

int PlaneTypeTable::hash(PlaneType planeType){
	int key, sum=0;
	int table_size = 23;
	sum+=planeType.make[0];
	sum+=planeType.make[1];
	sum+=planeType.model[0];
	sum+=planeType.model[1];
	key = sum % table_size;
	return key;		
}
	
void PlaneTypeTable::insert(PlaneType planeType){
	planeTypeTable[hash(planeType)].push_back(planeType);
	
}
	
void PlaneTypeTable::display(){
	cout<<"Plane Type Table"<<endl;
	cout<<"Make\t Model\t Flying Speed\t Ground Speed\n";
	for (int i=0; i < planeTypeTable.size(); i++){  //traverse the indexes
		for (PlaneType j : planeTypeTable[i]){
			cout<<j.make<<"\t"<<j.model<<"\t"<<j.flySpeed<<"\t\t"<<j.groundSpeed<<endl;
		}
	}		
}

PlaneTypeTable::PlaneTypeTable(int size)
{
	tableSize = size;
	planeTypeTable.resize(size);
}

