#Declaring Variables
HEADER = pet.h cat.h dog.h 
CPP = main.cpp pet.cpp cat.cpp dog.cpp
.o = main.o pet.o cat.o dog.o
PROGNAME = prog

#Compile .o has changed
arr: $(.o)
	g++ $(.o) -o $(PROGNAME)
	rm *.o
#Compile CPP has changed
all: $(.CPP) $(HEADER)
	g++ -c $(CPP)
#Clear file from executables
clear:
	rm *.o $(PROGNAME)


