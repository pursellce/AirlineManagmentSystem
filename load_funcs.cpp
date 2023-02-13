#include "load_funcs.h"

void load(string filename,hashAirport* myAirport, hashpilot* myPilots, FlightInstanceTable* myFlightInstance, FlightLegInstanceTable* myFlightLegInstance, FlightLegTable* myFlightLeg, FlightTable* myFlight, PlaneSeatsTable* mySeats, PlaneTable* myPlanes, PlaneTypeTable* myPlaneType){
	//intilize hashtable objects
	
	//open file, if file is not valid print message and exit
		ifstream file;
		file.open(filename);
		if(file.fail()){
			cout << "Invalid filename provided.\n";
			exit(1);
		}
	
	//parse input file to find .CSV files
		string output;
		for(int i = 0; i < 11; ++i){
			//getline from file
				getline(file,output);
			
			//find end of filename, resize string to just filename
				int csvLocation;
				csvLocation = output.find(".CSV");
				output.resize(csvLocation+4);
			
			//call appropriate load function based on which filename is extracted
				if(output == "DATA_Plane.CSV"){
					//cout << "DATA_Plane.CSV found\n";
					//cout << "-------------------------------------------------\n";
					loadPlane(output, myPlanes);
				}
				else if(output == "DATA_PlaneType.CSV"){
					//cout << "DATA_PlaneType.CSV found\n";
					//cout << "-------------------------------------------------\n";
					loadPlaneType(output, myPlaneType);
				}
				else if(output == "DATA_FlightLeg.CSV"){
					//cout << "DATA_FlightLeg.CSV found\n";
					//cout << "-------------------------------------------------\n";
					loadFlightLeg(output, myFlightLeg);
				}
				else if(output == "DATA_PlaneSeats.CSV"){
					//cout << "DATA_PlaneSeats.CSV found\n";
					//cout << "-------------------------------------------------\n";
					loadPlaneSeats(output, mySeats);
				}
				else if(output == "DATA_FlightLegInstance.CSV"){
					//cout << "DATA_FlightLegInstance.CSV found\n";
					//cout << "-------------------------------------------------\n";
					loadFlightLegInstance(output, myFlightLegInstance);
				}
				else if(output == "DATA_Pilot.CSV"){
					//cout << "DATA_Pilot.CSV found\n";
					//cout << "-------------------------------------------------\n";
					loadPilot(output, myPilots);
				}
				else if(output == "DATA_FlightInstance.CSV"){
					//cout << "DATA_FlightInstance.CSV found\n";
					//cout << "-------------------------------------------------\n";
					loadFlightInstance(output, myFlightInstance);
				}
				else if(output == "DATA_Reservation.CSV"){
					//cout << "DATA_Reservation.CSV found\n";
					//cout << "-------------------------------------------------\n";
					loadReservation(output);
				}
				else if(output == "DATA_Passenger.CSV"){
					//cout << "DATA_Passenger.CSV found\n";
					//cout << "-------------------------------------------------\n";
					loadPassenger(output);
				}
				else if(output == "DATA_AirPort.CSV"){
					//cout << "DATA_AirPort.CSV found\n";
					//cout << "-------------------------------------------------\n";
					loadAirPort(output, myAirport);
				}
				else if(output == "DATA_Flight.CSV"){
					//implement flight load func
				}
		}
	
	//close file
		file.close();
}

void loadPlane(string filename, PlaneTable* myPlanes){
	//open file, if file is not valid print message and exit
		ifstream file;
		file.open(filename);
		if(file.fail()){
			cout << "Invalid CSV filename " << filename << endl;
			return;
		}
		
	//parse csv file
		string output;
		getline(file, output); //ignore header
		while(getline(file, output)){
			//remove newline
				output.pop_back();
			//create string stream to process row
				stringstream valuestream(output);
			//used to store value between commas
				string value; 
			//parse line into planeEntry stuct
				Plane temp;
				getline(valuestream, value, ',');
				temp.ID = stoi(value);
				getline(valuestream, value, ',');
				temp.make = value;
				getline(valuestream, value, ',');
				temp.model = value;
				getline(valuestream, value, ',');
				temp.lastMaint = value;
				getline(valuestream, value, ',');
				temp.lastMaintAirport = value;
				myPlanes->insert(temp);
				//cout << temp.ID << " " << temp.make << " " << temp.model << " " << temp.lastMaint << " " << temp.lastMaintAirport << endl;
			//todo: use insert function for plane table when implemented
			
		}
	
	//close file
		file.close();
}

void loadPlaneType(string filename, PlaneTypeTable* myPlaneType){
	//open file, if file is not valid print message and exit
		ifstream file;
		file.open(filename);
		if(file.fail()){
			cout << "Invalid CSV filename " << filename << endl;
			return;
		}
		
	//parse csv file
		string output;
		getline(file, output); //ignore header
		while(getline(file, output)){
			//remove newline
				output.pop_back();
			//create string stream to process row
				stringstream valuestream(output);
			//used to store value between commas
				string value; 
			//parse line into planeTypeEntry struct
				PlaneType temp;
				getline(valuestream, value, ',');
				temp.make = value;
				getline(valuestream, value, ',');
				temp.model = value;
				getline(valuestream, value, ',');
				temp.flySpeed = stoi(value);
				getline(valuestream, value, ',');
				temp.groundSpeed = stoi(value);
				myPlaneType->insert(temp);
				//cout << temp.make << " " << temp.model << " " << temp.flySpeed << " " << temp.groundSpeed << endl;
				//todo: call insert function
		}
	
	//close file
		file.close();
}

void loadFlightLeg(string filename, FlightLegTable* myFlightLeg){
	//open file, if file is not valid print message and exit
		ifstream file;
		file.open(filename);
		if(file.fail()){
			cout << "Invalid CSV filename " << filename << endl;
			return;
		}
		
	//parse csv file
		string output;
		getline(file, output); //ignore header
		while(getline(file, output)){
			//remove newline
				//output.pop_back(); 
			//create string stream to process row
				stringstream valuestream(output);
			//used to store value between commas
				string value; 
			//parse line into flightLegEntry struct
				flightLegEntry temp;
				getline(valuestream, value, ',');
				temp.flightNum = stoi(value);
				getline(valuestream, value, ',');
				temp.sequence = stoi(value);
				getline(valuestream, value, ',');
				//remove quotes
					value.pop_back();
					value.erase(value.begin());
					temp.fromAirport = value;
				getline(valuestream, value, ',');
				//remove quotes
					value.pop_back();
					value.erase(value.begin());
					temp.toAirport = value;
				getline(valuestream, value, ',');
				temp.depDate = value;
				getline(valuestream, value, ',');
				temp.arvDate = value;
				getline(valuestream, value, ',');
				temp.plane = stoi(value);
				myFlightLeg->Insert(temp);
				//cout << temp.flightNum << " " << temp.sequence << " " << temp.fromAirport << " " << temp.toAirport << " " << temp.depDate << " " << temp.arvDate << " " << temp.plane << endl;
				//todo: call insert function
		}
	
	//close file
		file.close();
}

void loadPlaneSeats(string filename, PlaneSeatsTable* mySeats){
	//open file, if file is not valid print message and exit
		ifstream file;
		file.open(filename);
		if(file.fail()){
			cout << "Invalid CSV filename " << filename << endl;
			return;
		}
		
	//parse csv file
		string output;
		getline(file, output); //ignore header
		while(getline(file, output)){
			//remove newline
				output.pop_back();
			//create string stream to process row
				stringstream valuestream(output);
			//used to store value between commas
				string value; 
			//parse line into seatsEntry struct
				PlaneSeats temp;
				getline(valuestream, value, ',');
				temp.make = value;
				getline(valuestream, value, ',');
				temp.model = value;
				getline(valuestream, value, ',');
				temp.seatType = value.at(0);
				getline(valuestream, value, ',');
				temp.numSeats = stoi(value);
				mySeats->insert(temp);
				//cout << temp.make << " " << temp.model << " " << temp.seatType << " " << temp.numSeats << endl;
				//todo: call insert function
		}
	
	//close file
		file.close();
}

void loadFlightLegInstance(string filename, FlightLegInstanceTable* myFlightLegInstance){
	//open file, if file is not valid print message and exit
		ifstream file;
		file.open(filename);
		if(file.fail()){
			cout << "Invalid CSV filename " << filename << endl;
			return;
		}
		
	//parse csv file
		string output;
		getline(file, output); //ignore header
		while(getline(file, output)){
			//remove newline
				output.pop_back();
			//create string stream to process row
				stringstream valuestream(output);
			//used to store value between commas
				string value; 
			//parse line into flightLegInstanceEntry struct
				flightLegInstanceEntry temp;
				getline(valuestream, value, ',');
				temp.sequence = stoi(value);
				getline(valuestream, value, ',');
				temp.flightNum = stoi(value);
				getline(valuestream, value, ',');
				temp.flightDate = value;
				getline(valuestream, value, ',');
				temp.depDate = value;
				getline(valuestream, value, ',');
				temp.arvDate = value;
				value = "";
				getline(valuestream, value, ',');
				if(!value.empty()){
					temp.pilot = stoi(value);
				}
				else{
					temp.pilot = -1; //set to -1, no pilot assigned yet
				}
				myFlightLegInstance->Insert(temp);
				//cout << temp.sequence << " " << temp.flightNum << " " << temp.flightDate << " " << temp.depDate << " " << temp.arvDate << " " << temp.pilot << endl;
				//todo: call insert function
				
		}
	
	//close file
		file.close();
}

void loadAirPort(string filename, hashAirport* myAirport){
	//open file, if file is not valid print message and exit
		ifstream file;
		file.open(filename);
		if(file.fail()){
			cout << "Invalid CSV filename " << filename << endl;
			return;
		}
		
	//parse csv file
		string output;
		getline(file, output); //ignore header
		while(getline(file, output)){
			//remove newline
				output.pop_back();
			//create string stream to process row
				stringstream valuestream(output);
			//used to store value between commas
				string value; 
			//parse into airportEntry struct
				airport temp;
				getline(valuestream, value, ',');
				temp.code = value;
				getline(valuestream, value, ',');
				temp.city = value;
				getline(valuestream, value, ',');
				temp.state = value;
				myAirport->Insert(temp);
				//cout << temp.code << " " << temp.city << " " << temp.state << endl;
				//todo: call insert function
		}
	
	//close file
		file.close();
}

void loadPilot(string filename, hashpilot* myPilots){
	//open file, if file is not valid print message and exit
		ifstream file;
		file.open(filename);
		if(file.fail()){
			cout << "Invalid CSV filename " << filename << endl;
			return;
		}
	
	//parse csv file
		string output;
		getline(file, output); //ignore header
		while(getline(file, output)){
			//remove newline
				output.pop_back();
			//create string stream to process row
				stringstream valuestream(output);
			//used to store value between commas
				string value; 
			//parse line into pilotEntry struct
				pilot temp;
				getline(valuestream, value, ',');
				temp.ID = stoi(value);
				getline(valuestream, value, ',');
				temp.name = value;
				getline(valuestream, value, ',');
				temp.dateHired = value;
				myPilots->Insert(temp);
				//cout << temp.ID << " " << temp.name << " " << temp.dateHired << endl;
				//todo: call insert function
		}
	
		
	
	//close file
		file.close();
}

void loadFlightInstance(string filename, FlightInstanceTable* myFlightInstance){
	//open file, if file is not valid print message and exit
		ifstream file;
		file.open(filename);
		if(file.fail()){
			cout << "Invalid CSV filename " << filename << endl;
			return;
		}
	
	//parse csv file
		string output;
		getline(file, output); //ignore header
		while(getline(file, output)){
			//remove newline
				output.pop_back();
			//create string stream to process row
				stringstream valuestream(output);
			//used to store value between commas
				string value; 
			//parse line into flightEntry struct
				flightInstanceEntry temp;
				getline(valuestream, value, ',');
				temp.flightNum = stoi(value);
				getline(valuestream, value, ',');
				temp.date = value;
				myFlightInstance->Insert(temp);
				//cout << temp.flightNum << " " << temp.date << endl;
				//todo: call insert function
		}
	
	//close file
		file.close();
}

void loadReservation(string filename){
	//open file, if file is not valid print message and exit
		ifstream file;
		file.open(filename);
		if(file.fail()){
			cout << "Invalid CSV filename " << filename << endl;
			return;
		}
		
	//parse csv file
		string output;
		getline(file, output); //ignore header
		while(getline(file, output)){
			//remove newline
				output.pop_back();
			//create string stream to process row
				stringstream valuestream(output);
			//used to store value between commas
				string value; 
			//parse line into reservationEntry struct
				reservationEntry temp;
				getline(valuestream, value, ',');
				temp.passId = stoi(value);
				getline(valuestream, value, ',');
				temp.flightNum = stoi(value);
				getline(valuestream, value, ',');
				temp.flightDate = value;
				getline(valuestream, value, ',');
				temp.fromAirport = value;
				getline(valuestream, value, ',');
				temp.toAirport = value;
				getline(valuestream, value, ',');
				temp.seatClass = value.at(0);
				getline(valuestream, value, ',');
				temp.dateBooked = value;
				getline(valuestream, value, ',');
				temp.dateCancelled = value;
				//cout << temp.passId << " " << temp.flightNum << " " << temp.flightDate << " " << temp.fromAirport << " " << temp.toAirport << " " << temp.seatClass << " " << temp.dateBooked << " " << temp.dateCancelled << endl;
				//todo: call insert function
				
		}
	
	//close file
		file.close();
}

void loadPassenger(string filename){
	//open file, if file is not valid print message and exit
		ifstream file;
		file.open(filename);
		if(file.fail()){
			cout << "Invalid CSV filename " << filename << endl;
			return;
		}
		
	//parse csv file
		string output;
		getline(file, output); //ignore header
		while(getline(file, output)){
			//remove newline
				output.pop_back();
			//create string stream to process row
				stringstream valuestream(output);
			//used to store value between commas
				string value; 
			//parse line into passEntry struct
				passEntry temp;
				getline(valuestream, value, ',');
				temp.id = stoi(value);
				getline(valuestream, value, ',');
				//remove quotes
					value.pop_back();
					value.erase(value.begin());
					temp.name = value;
				getline(valuestream, value, ',');
					value.erase(value.begin());
					temp.phoneNum = value;
				//cout << temp.id << " " << temp.name << " " << temp.phoneNum << endl;
				//todo: call insert function
		}
	
	//close file
		file.close();
}