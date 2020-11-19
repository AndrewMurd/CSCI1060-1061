# Lets specify compiler
CC = g++
CFLAGS = -c
AR = ar

# Source files.  We keep header files separate from the cpp files.
# Recall that we will compile cpp files, but we do not compile
# the header files.
HEADER = menu.h
CPP = menu.cpp

# Program name
LIBNAME = libmenu.a

# Object files
OBJ = $(CPP:.cpp=.o)

all: $(LIBNAME)

$(LIBNAME): $(OBJ)
	$(AR) -r $@ $<

%.o: %.cpp $(HEAD	ER)
	$(CC) $(CFLAGS) -o $@ $<

install: $(HEADER) $(LIBNAME)
	cp -f menu.h ../
	cp -f $(LIBNAME) ../

# Target clean is phony, since it doesn't
# create a file called clean.  Notice that other
# targets --- all and message --- create file
# message.
.PHONY: clean

# We will use target clean to delete both the object files
# and the program.
clean:
	rm -rf $(LIBNAME) $(OBJ)
