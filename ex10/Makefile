# Name: Chenyang Fang
 
# Makefile
CC = g++
CFLAGS = -Wall -g -std=c++11

# default target
ex10: ex10.o Vector.o
	$(CC) $(CFLAGS) -o $@ $^

# individual source files
Vector.o: Vector.cc Vector.h
	$(CC) $(CFLAGS) -c $<

ex10.o: ex10.cc Vector.h
	$(CC) $(CFLAGS) -c $<

# phony target
clean:
	rm -rf ex10 *.o *~ *.dSYM
