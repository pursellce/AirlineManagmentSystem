#ifndef STRUCTS_H
#define STRUCTS_H

using namespace std;

/*Replaced with structs in plane and planetype
struct planeEntry{
	int id;
	string make;
	string model;
	string lastMaint;
	string lastMaintAirport;	
};

struct planeTypeEntry{
	string make;
	string model;
	int flySpeed;
	int groundSpeed;
};
*/

struct flightLegEntry{
	int flightNum;
	int sequence;
	string fromAirport;
	string toAirport;
	string depDate;
	string arvDate;
	int plane;
};
/* Replaced with structs in planeseats
struct seatsEntry{
	string make;
	string model;
	char seatType;
	int numSeats;
};*/

struct flightLegInstanceEntry{
	int sequence;
	int flightNum;
	string flightDate;
	string depDate;
	string arvDate;
	int pilot;
};

/* replaced by struct in airport.h
struct airportEntry{
	string code;
	string city;
	string state;
};
*/

/* replaced by struct in pilot.h
struct pilotEntry{
	int id;
	string name;
	string hireDate;
};
*/

struct flightInstanceEntry{
	int flightNum;
	string date;
};

struct reservationEntry{
	int passId;
	int flightNum;
	string flightDate;
	string fromAirport;
	string toAirport;
	char seatClass;
	string dateBooked;
	string dateCancelled;
};

struct passEntry{
	int id;
	string name;
	string phoneNum;
};

struct flightEntry{
	int flightNum;
	string meal;
	char smoking;
};

#endif
