
#Declaring Variables
HEADER = mat3.h
CPP = main.cpp class.cpp
.o = main.o class.o
PROGNAME = prog

#Compile .o has changed
arr: $(.o)
	g++ $(.o) -o $(PROGNAME)
#Compile CPP has changed
all: $(.CPP) $(HEADER)
	g++ -c $(CPP)
#Clear file from executables
clear:
	rm *.o $(PROGNAME)

