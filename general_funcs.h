#ifndef GEN_FUNCS_H
#define GEN_FUNCS_H

using namespace std;
#include <iostream>
#include "Pilot.h"
#include "Airport.h"
#include "FlightInstanceTable.h"
#include "FlightLegInstanceTable.h"
#include "FlightLegTable.h"
#include "FlightTable.h"
#include "planeseats.h"
#include "plane.h"
#include "planetype.h"

void display(hashAirport*, hashpilot*, FlightInstanceTable*, FlightLegInstanceTable*, FlightLegTable*, FlightTable*, PlaneSeatsTable*, PlaneTable*, PlaneTypeTable*);

#endif