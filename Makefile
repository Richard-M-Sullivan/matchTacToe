# executable of final project

TARGET = matchbox   # change target to change executible name


# lists of important files

MAIN = $(wildcard src/*.cpp)
FILES = $(wildcard lib/*.cpp)
HEADERS = $(wildcard include/*.h)
OBJS := $(FILES:.cpp=.o)


# location of tests

TESTDIR = ./tests/


# compiler settings

CXX = g++
CFLAGS = -g -Iinclude
LFLAGS = -lncurses 


# build the executable for the final project

.PHONY:all
all:$(TARGET)


# build the specified test and run it
# this depends on all the object files and the specified test file

%test:$(OBJS)
	$(CXX) -c $(TESTDIR)$@.cpp -o $(TESTDIR)$@.o $(CFLAGS)
	$(CXX) -o $@ $(OBJS) $(TESTDIR)$@.o $(LFLAGS)

# the final executable depends on all the object files and main

$(TARGET):$(OBJS)
	$(CXX) -c $(MAIN) -o $(MAIN:.cpp=.o) $(CFLAGS)
	$(CXX) -o $(TARGET) $(MAIN:.cpp=.o) $(OBJS) $(LFLAGS)


# all of the .o files depend on the specified .cpp file

%.o:%.cpp
	$(CXX) -c $< -o $@ $(CFLAGS)


# run the project executable - for this project it does not work because
#   command are needed line options are needed

.PHONY:run
run:
	./$(TARGET)


# clean the project of .o files and the executable - this does not effect the
#   test files or remove test executables

.PHONY:clean
clean:
	rm -f $(TARGET) $(OBJS)


# this opens all the project files, but does not open the test files

.PHONY:vim
vim: 
	vim $(MAIN) $(FILES) $(HEADERS)


# this makes an empty project for this makefile

.PHONY: project
project: 
	mkdir src lib include tests
	touch ./src/main.cpp
	echo "#include <iostream> \n\nint main() { \n    return 0; \n}" > ./src/main.cpp


# this runs the final projec with the tictactoe commandline argument,
#   it depends on the project being built

.PHONY: tic
tic: all
	./$(TARGET) tictactoe


# this runs the final projec with the hexapawn commandline argument,
#   it depends on the project being built

.PHONY: hex
hex: all
	./$(TARGET) hexapawn
