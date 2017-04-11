CFLAGS = -O -std=c++11
CC = g++

Algo: main.o AdjacencyMatrix.o
	$(CC) $(CFLAGS) -o Algo main.o AdjacencyMatrix.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

AdjacencyMatrix.o: AdjacencyMatrix.cpp
	$(CC) $(CFLAGS) -c AdjacencyMatrix.cpp

clean:
	rm -f core *.o
