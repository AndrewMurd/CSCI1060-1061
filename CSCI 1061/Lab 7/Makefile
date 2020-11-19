#Declaring Variables
HEADER = Buffer.h Stack.h StackInt.h
CPP = main.cpp Stack.cpp Buffer.cpp StackInt.cpp
OBJ = $(CPP:.cpp=.o)
PROGNAME = prog

#Compile .o has changed
arr: $(OBJ)
	g++ $(OBJ) -o $(PROGNAME)
	rm *.o
#Compile CPP has changed
all: $(.CPP) $(HEADER)
	g++ -c $(CPP)
#Clear file from executables
clear:
	rm *.o $(PROGNAME)