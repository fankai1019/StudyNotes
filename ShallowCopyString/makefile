cc = g++
cflags = -Wall -g
main : main.cpp string.o stringrep.o
	$(cc) $(cflags) main.cpp string.o stringrep.o -o main
string.o : string.cpp stringrep.o
	$(cc) $(cflags) -c string.cpp
stringrep.o : stringrep.cpp
	$(cc) $(cflags) -c stringrep.cpp
clean:
	-rm -f *.o main

