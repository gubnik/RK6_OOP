CC = g++
FLAGS = -std=c++11 -O3 -Wpedantic
# Extension for compiled code
E=.out

main: exletter_set main.cpp
	$(CC) $(FLAGS) exletter_set$E -o lab$E main.cpp

exletter_set: exletter_set.hpp exletter_set.cpp
	$(CC) $(FLAGS) -o exletter_set$E -c exletter_set.cpp
