CC=g++
FLAGS=-std=c++17 -Wpedantic

h=bits/
c=cpps/
b=bin/

P=piece
F=field
B=board
R=renderer

main: main.cpp $B $R $h
	$(CC) $b$P.o $b$F.o $b$B.o $b$R.o $(FLAGS) -fsanitize=address -o main.o main.cpp

$R: $F $h$R.hpp $c$R.cpp
	$(CC) $(FLAGS) -o bin/$R.o -c $c$R.cpp

$B: $F $h$B.hpp $c$B.cpp
	$(CC) $(FLAGS) -o bin/$B.o -c $c$B.cpp

$F: $P $h$F.hpp $c$F.cpp
	$(CC) $(FLAGS) -o bin/$F.o -c $c$F.cpp

$P: $h$P.hpp $c$P.cpp
	$(CC) $(FLAGS) -o $b$P.o -c $c$P.cpp
