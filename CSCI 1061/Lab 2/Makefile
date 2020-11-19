#Compile main.o and count.o if they have changed
arr: main.o count.o
	g++ main.o count.o -o arr
#Compile main.cpp and count.cpp if they have changed
all: main.cpp count.cpp count.h
	g++ -c main.cpp count.cpp
#Clear file from executables
clear:
	rm *.o arr



