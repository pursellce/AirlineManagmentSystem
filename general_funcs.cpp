#include "general_funcs.h"

void display(hashAirport* airport, hashpilot* pilot, FlightInstanceTable* flightinstance, FlightLegInstanceTable* leginstance, FlightLegTable* flightleg, FlightTable* flight, PlaneSeatsTable* planeSeats, PlaneTable* plane, PlaneTypeTable* planeType){
	//call each individual hash table's display functions
	cout << "-------------------------------------------------\n";
	planeType->display();
	cout << "-------------------------------------------------\n";
	flight->Display();
	cout << "-------------------------------------------------\n";
	leginstance->Display();
	cout << "-------------------------------------------------\n";
	airport->Display();
	cout << "-------------------------------------------------\n";
	pilot->Display();
	cout << "-------------------------------------------------\n";
	planeSeats->display();
	cout << "-------------------------------------------------\n";
	plane->display();
	cout << "-------------------------------------------------\n";
	flightinstance->Display();
	cout << "-------------------------------------------------\n";
	flightleg->Display();
	cout << "-------------------------------------------------\n";
}