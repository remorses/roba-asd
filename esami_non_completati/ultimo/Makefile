all: graph main
	g++ -o mappe graph.o main.o
	/bin/rm graph.o main.o

graph: graph.cpp graph.h
	g++ -c -std=c++11 graph.cpp

main: main.cpp graph.h
	g++ -c -std=c++11 main.cpp

clean:
	/bin/rm -f graph.o main.o mappe
