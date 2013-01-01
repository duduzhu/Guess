CC=g++
CFLAGS=-O3 -c -Wall
TARGET=guess

all: main

main: main.o puzzle.o puzzlesolver.o
	$(CC) main.o puzzle.o puzzlesolver.o -o $(TARGET)
main.o: main.cpp puzzle.o puzzlesolver.o
	$(CC) $(CFLAGS) main.cpp
puzzle.o: puzzle.cpp puzzle.h
	$(CC) $(CFLAGS) puzzle.cpp

puzzlesolver.o: puzzlesolver.cpp puzzlesolver.h
	$(CC) $(CFLAGS) puzzlesolver.cpp
clean:
	rm -rf *o $(TARGET)
