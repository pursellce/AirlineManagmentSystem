using namespace std;
#include "Pilot.h"
#include "Airport.h"
#include "FlightInstanceTable.h"
#include "FlightLegInstanceTable.h"
#include "FlightLegTable.h"
#include "FlightTable.h"
#include "planeseats.h"
#include "plane.h"
#include "planetype.h"
#include "load_funcs.h"
#include "general_funcs.h"

int main(int argc, char *argv[]){
	//crete hash tables object
		hashAirport* myAirport = new hashAirport(23);
		hashpilot* myPilots = new hashpilot;
		FlightInstanceTable* flightInstanceTable = new FlightInstanceTable(23);
		FlightLegInstanceTable* flightLegInstanceTable = new FlightLegInstanceTable(23);
		FlightLegTable* flightLegTable = new FlightLegTable(23);
		FlightTable* flightTable = new FlightTable(23);
		PlaneSeatsTable* planeSeats = new PlaneSeatsTable(23);
		PlaneTable* plane = new PlaneTable(23);
		PlaneTypeTable* planeType = new PlaneTypeTable(23);
	
	//check that argument was provided
		if (argc == 1){
			cout << "Usage: ./project2.out filename\n";
			exit(1);
		}
	
	//get instructions filename from argument 
		string filename;
		filename = argv[1];
	
	//call load function
		load(filename, myAirport, myPilots, flightInstanceTable, flightLegInstanceTable, flightLegTable, flightTable, planeSeats, plane, planeType);
		
	//open file, if file is not valid print message and exit
		ifstream file;
		file.open(filename);
		if(file.fail()){
			cout << "Invalid filename provided.\n";
			exit(1);
		}
	
	//skip first 10 lines of file
	string input;
	for(int i = 0; i < 10; ++i){
		getline(file,input);
	}
	
	while(getline(file,input)){
		input.pop_back();
		//cout << "[" << input << "]" << endl;
		if(input == "DISPLAY()"){
			display(myAirport, myPilots, flightInstanceTable, flightLegInstanceTable, flightLegTable, flightTable, planeSeats, plane, planeType);
			exit(1);
		}
	}
	
	
	//close file
		file.close();
	
	
}