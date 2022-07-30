CXX=g++
CXXFLAGS=-std=c++17 -ggdb -Wall
LIBS=-lm

SRC=$(wildcard src/*.cpp)
OBJS=$(addprefix obj/, $(SRC:.cpp=.o))

.PHONY: dirs clean

all: dirs lib example

example: example.cpp
	$(CXX) $(CXXFLAGS) -Isrc $< $(LIBS) -Llib -lmt

lib: $(OBJS)
	$(AR) $(ARFLAGS) lib/libmt.a $^

obj/src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

dirs:
	mkdir -p obj/src lib

clean:
	-rm -rf obj/src lib a.out

