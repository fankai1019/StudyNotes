cc = g++
cflags = -Wall -g -std=c++11
main : main.cpp String.o StringRep.o
	$(cc) $(cflags) main.cpp String.o StringRep.o -o main
String.o : String.cpp StringRep.o
	$(cc) $(cflags) -c String.cpp
StringRep.o : StringRep.cpp
	$(cc) $(cflags) -c StringRep.cpp
clean:
	-rm -f *.o main

