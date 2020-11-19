# Lets specify compiler
CC = g++
CFLAGS = -c

# Source files.  We keep header files separate from the cpp files.
# Recall that we will compile cpp files, but we do not compile
# the header files.
HEADER = menu.h
CPP = lesson-4.cpp
LIB = libmenu.a

# Program name
PROGNAME = lesson-4

# Object files
OBJ = $(CPP:.cpp=.o)

all: $(PROGNAME)

$(PROGNAME): $(OBJ) $(LIB)
	$(CC) -o $@ $(OBJ) -lmenu -L .

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -o $@ $<

run: $(PROGNAME)
	./$(PROGNAME)

# Target clean is phony, since it doesn't
# create a file called clean.  Notice that other
# targets --- all and message --- create file
# message.
.PHONY: clean

# We will use target clean to delete both the object files
# and the program.
clean:
	rm -rf $(PROGNAME) $(OBJ)
