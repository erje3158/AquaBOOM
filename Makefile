# AquaBOOM Makefile
# macOS

NAME = AquaBOOM
CXX = g++
OPT = -std=c++0x -Wall -g
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

%.o : %.cpp
	$(CXX) -c -o $@ $^ $(OPT)

$(NAME) : $(OBJECTS)
	$(CXX) -o $@ $^ $(OPT)

clean :
	rm -rf *.o *.mod $(programName) *~ *.out
	