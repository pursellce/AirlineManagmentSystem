OBJS	= main.o load_funcs.o general_funcs.o Pilot.o Airport.o plane.o planeseats.o planetype.o FlightInstanceTable.o FlightLegInstanceTable.o FlightLegTable.o FlightTable.o
SOURCE	= main.cpp load_funcs.cpp general_funcs.cpp Pilot.cpp Airport.cpp plane.cpp planeseats.cpp planetype.cpp FlightInstanceTable.cpp FlightLegInstanceTable.cpp FlightLegTable.cpp FlightTable.cpp
HEADER	= load_funcs.h general_funs.h Pilot.h Airport.h plane.h planeseats.h planetype.h FlightInstanceTable.h FlightLegInstanceTable.h FlightLegTable.h FlightTable.h
OUT	= project2.out
CC	 = g++
FLAGS	 = -g -c
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

load_funcs.o: load_funcs.cpp
	$(CC) $(FLAGS) load_funcs.cpp 

general_funcs.o: general_funcs.cpp
	$(CC) $(FLAGS) general_funcs.cpp 

Pilot.o: Pilot.cpp
	$(CC) $(FLAGS) Pilot.cpp 

Airport.o: Airport.cpp
	$(CC) $(FLAGS) Airport.cpp 

plane.o: plane.cpp
	$(CC) $(FLAGS) plane.cpp

planeseats.o: planeseats.cpp
	$(CC) $(FLAGS) planeseats.cpp

planetype.o: planetype.cpp
	$(CC) $(FLAGS) planetype.cpp
	
FlightInstanceTable.o: FlightInstanceTable.cpp
	$(CC) $(FLAGS) FlightInstanceTable.cpp 

FlightLegInstanceTable.o: FlightLegInstanceTable.cpp
	$(CC) $(FLAGS) FlightLegInstanceTable.cpp 
	
FlightLegTable.o: FlightLegTable.cpp
	$(CC) $(FLAGS) FlightLegTable.cpp 
	
FlightTable.o: FlightTable.cpp
	$(CC) $(FLAGS) FlightTable.cpp 

clean:
	rm -f $(OBJS) $(OUT)