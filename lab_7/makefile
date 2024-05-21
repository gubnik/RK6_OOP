CC=g++
FLAGS=-std=c++17 -Wpedantic

h=bits/
c=cpps/
b=bin/

P=piece
F=field
B=board
R=renderer

main: main.cpp $b$R.o $b$B.o $b$F.o $b$P.o
	$(CC) $b$P.o $b$F.o $b$B.o $b$R.o $(FLAGS) -o main.o main.cpp

$b%.o: $c%.cpp $h%.hpp
	$(CC) $(FLAGS) -o $@ -c $<
