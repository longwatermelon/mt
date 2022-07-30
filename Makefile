CXX=g++
CXXFLAGS=-std=c++17 -ggdb -Wall
LIBS=-lm

SRC=$(wildcard src/*.cpp)
OBJS=$(addprefix obj/, $(SRC:.cpp=.o))

.PHONY: dirs clean

all: dirs example

example: example.cpp
	$(CXX) $(CXXFLAGS) -Iinclude $< $(LIBS)

dirs:
	mkdir -p obj/src

clean:
	-rm -rf obj/src a.out

