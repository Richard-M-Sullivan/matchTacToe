# VARIABLES

FILES = $(wildcard src/*.cpp) $(wildcard lib/*.cpp)
HEADERS = $(wildcard include/*.h)
OBJS = $(FILES:.cpp=.o)
TARGET = exeName   # change target to change executible name

CXX = g++

CFLAGS = -std=c++11 -Iinclude
LFLAGS = 


.PHONY: all
all: $(TARGET)

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LFLAGS)

%.o:	%.cpp
	$(CXX) -c $< -o $@ $(CFLAGS)


.PHONY: run
run:
	./$(TARGET)


.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)


.PHONY: vim
vim: 
	vim $(FILES) $(HEADERS)


.PHONY: project
project: 
	mkdir src lib include
	touch ./src/main.cpp
	echo "#include <iostream> \n\nint main() { \n    return 0; \n}" > ./src/main.cpp
