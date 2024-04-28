CC = g++
FLAGS = -std=c++11 -Wpedantic -O3

main: vertex main.cpp
	$(CC) $(FLAGS) vertex -o lab main.cpp

vertex: vertex.hpp vertex.cpp
	$(CC) $(FLAGS) -o vertex -c vertex.cpp
