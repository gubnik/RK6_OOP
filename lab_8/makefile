CC=g++
FLAGS=-std=c++11 -Wpedantic

S=fsearch

main.o: main.cpp $S.o
	$(CC) $S.o $(FLAGS) -o $@ $<

%.o: %.cpp %.hpp
	$(CC) $(FLAGS) -o $@ -c $<
