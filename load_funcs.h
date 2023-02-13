#ifndef LOAD_FUNCS_H
#define LOAD_FUNCS_H

using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "structs.h"
#include "FlightInstanceTable.h"
#include "FlightLegInstanceTable.h"
#include "FlightLegTable.h"
#include "FlightTable.h"
#include "Pilot.h"
#include "Airport.h"
#include "plane.h"
#include "planeseats.h"
#include "planetype.h"

void load(string,hashAirport*, hashpilot*, FlightInstanceTable*, FlightLegInstanceTable*, FlightLegTable*, FlightTable*, PlaneSeatsTable*, PlaneTable*, PlaneTypeTable*);
void loadPlane(string filename, PlaneTable* myPlanes);
void loadPlaneType(string filename, PlaneTypeTable* myPlaneType);
void loadFlightLeg(string filename, FlightLegTable* myFlightLeg);
void loadPlaneSeats(string filename, PlaneSeatsTable* mySeats);
void loadFlightLegInstance(string filename, FlightLegInstanceTable* myFlightLegInstance);
void loadAirPort(string filename, hashAirport* myAirport);
void loadPilot(string filename, hashpilot* myPilots);
void loadFlightInstance(string filename, FlightInstanceTable* myFlightInstance);
void loadReservation(string filename);
void loadPassenger(string filename);

#endif