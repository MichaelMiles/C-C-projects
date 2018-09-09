# Name: Chenyang Fang

# Makefile
CC = g++
CFLAGS = -Wall -g -std=c++11

# default target
ex11: ex11.o Vector.o
	$(CC) $(CFLAGS) -o $@ $^

# individual source files
Vector.o: Vector.cc Vector.h
	$(CC) $(CFLAGS) -c $<

ex11.o: ex11.cc Vector.h
	$(CC) $(CFLAGS) -c $<

# phony target
clean:
	rm -rf ex11 *.o *~ *.dSYM
