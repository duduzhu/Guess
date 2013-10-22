CC=g++
CFLAGS=-O3 -c -Wall
LIBFLAGS=-fPIC -shared
TARGET=guess

all: main

main: main.o puzzle.so mypuzzlesolver.so
	$(CC) main.o -L. -lpuzzle -lmypuzzlesolver -o $(TARGET)
main.o: main.cpp puzzlesolver.h
	$(CC) $(CFLAGS) main.cpp
puzzle.so: puzzle.cpp puzzle.h
	$(CC) $(CFLAGS) $(LIBFLAGS) puzzle.cpp -o libpuzzle.so

mypuzzlesolver.so: mypuzzlesolver.cpp mypuzzlesolver.h puzzlesolver.h puzzle.h
	$(CC) $(CFLAGS) $(LIBFLAGS) mypuzzlesolver.cpp -o libmypuzzlesolver.so
clean:
	rm -rf *.o *.so $(TARGET)
nothing:
	export LD_LIBRARY_PATH
	ldd $(TARGET)
