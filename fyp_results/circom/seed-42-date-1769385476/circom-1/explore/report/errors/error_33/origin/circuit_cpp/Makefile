CC=g++
CFLAGS=-std=c++11 -O3 -I.
EXTRA_FILES = json2bin64.cpp
DEPS_HPP = circom.hpp calcwit.hpp fr.hpp
DEPS_CPP := $(filter-out $(EXTRA_FILES), $(wildcard *.cpp))
DEPS_O := $(patsubst %.cpp,%.o,$(DEPS_CPP))

all: circuit

%.o: %.cpp $(DEPS_HPP)
	$(CC) -c $< $(CFLAGS)

circuit: $(DEPS_O) circuit.o
	$(CC) -o circuit $(DEPS_O) -lgmp 

json2bin64: json2bin64.cpp
	$(CC) -o json2bin64 json2bin64.cpp -lgmp 
