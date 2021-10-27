
CC=gcc
CFLAGS=-g -Wall

all: tree

tree.o: tree.h tree.c
	$(CC) $(CFLAGS) -c tree.c

main: tree.o main.c
	$(CC) $(CFLAGS) main.c tree.o -o main.exe

tree:
	$(CC) $(CFLAGS) -o main.exe main.c tree.c

clear:
	rm *.o main.exe

reset:
	make clear
	make main
