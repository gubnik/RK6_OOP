CC=g++
FLAGS=-std=c++11 -Wpedantic
EX=main
S=dlstring

main: $(EX).cpp $S.hpp dlist.hpp
	$(CC) $(FLAGS) -o $(EX).o $(EX).cpp

sanitized:
	$(CC) $(FLAGS) -fsanitize=address -o SAN_$(EX).o $(EX).cpp

asm:
	$(CC) $(FLAGS) -S $(EX).cpp

clean:
	rm *.o
	rm *.s
	$(CC) $(FLAGS) -o $(EX).o $(EX).cpp
