CXX = g++
CPPFLAGS = -Wall -g -std=c++11

ex14: ex14.o Cartesian.o Polar.o
	$(CXX) $(CPPFLAGS) -o ex14 $^

ex14.o: ex14.cc Polar.h Cartesian.h
	$(CXX) $(CPPFLAGS) -c $<

Cartesian.o: Cartesian.cc Cartesian.h Coordinate.h
	$(CXX) $(CPPFLAGS) -c $<

Polar.o: Polar.cc Polar.h  Coordinate.h
	$(CXX) $(CPPFLAGS) -c $<

clean: 
	rm -r -f *.o ex14
