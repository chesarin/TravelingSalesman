#Cesar Vargas 
#AI Fall 2010
#TravelingSalesman Program
CC=g++

CFLAGS=-c -g -Wall

all: traveling

traveling: execute.o
	$(CC) execute.o -o traveling.exe

execute.o: execute.cpp
	$(CC) $(CFLAGS) execute.cpp

clean:
	rm -rf *o traveling.exe