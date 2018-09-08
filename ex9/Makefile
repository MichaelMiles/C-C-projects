CC = g++
CFLAGS = -Wall -g -std=c++11
PROGS = ex9

all: $(PROGS)

ex9: ex9.o IntPair.o
	$(CC) $(CFLAGS) -o $@ $^
	
ex9.o: ex9.cc IntPair.h
	$(CC) $(CFLAGS) -c $<

IntPair.o: IntPair.cc IntPair.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(PROGS) *.o
