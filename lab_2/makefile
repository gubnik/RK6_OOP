CC = g++
FLAGS = -std=c++11 -O3 -Wpedantic
# Extension for compiled code
E=.out

main: vertex main.cpp
	$(CC) $(FLAGS) vertex$E -o lab$E main.cpp

vertex: vertex.hpp vertex.cpp
	$(CC) $(FLAGS) -o vertex$E -c vertex.cpp
