#Cesar Vargas 
#AI Fall 2010
#TravelingSalesman Program
CC=g++

CFLAGS=-c -g -Wall

all: traveling

traveling: execute.o Graph.o
	$(CC) execute.o Graph.o -o traveling.exe

execute.o: execute.cpp
	$(CC) $(CFLAGS) execute.cpp

graph.o: Graph.cpp
	$(CC) $(CFLAGS) Graph.cpp

clean:
	rm -rf *o traveling.exe 