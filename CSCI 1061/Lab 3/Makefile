
#Declaring Variables
HEADER = str.h que.h
CPP = main.cpp str.cpp que.cpp
.o = main.o str.o que.o
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

