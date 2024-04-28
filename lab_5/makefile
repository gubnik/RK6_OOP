CC = g++
FLAGS = -std=c++11 -O3 -Wpedantic
# Extension for compiled code
E=.out

main: geom main.cpp
	$(CC) $(FLAGS) geom$E -o lab$E main.cpp

geom: geom.hpp geom.cpp
	$(CC) $(FLAGS) -o geom$E -c geom.cpp
