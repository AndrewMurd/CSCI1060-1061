#Declaring Variables
HEADER = rand-int.h rand-range.h
CPP = main.cpp rand-int.cpp rand-range.cpp
.o = main.o rand-int.o rand-range.o
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


