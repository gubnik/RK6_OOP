CC = g++
FLAGS = -std=c++11 -O3 -Wpedantic
# Extension for compiled code
E=.out

main: letter_set main.cpp
	$(CC) $(FLAGS) letter_set$E -o lab$E main.cpp

letter_set: letter_set.hpp letter_set.cpp
	$(CC) $(FLAGS) -o letter_set$E -c letter_set.cpp
