#Declaring Variables
HEADER = chess.h
CPP = main.cpp chess.cpp
.o = main.o chess.o
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

