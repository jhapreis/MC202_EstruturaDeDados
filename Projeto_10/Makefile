
CC=gcc
CFLAGS= -g3 -Wall

all: tree

tree.o: tree.h tree.c
	$(CC) $(CFLAGS) -c tree.c

main: tree.c main.c
	$(CC) $(CFLAGS) main.c tree.c -o main.exe

tree:
	$(CC) $(CFLAGS) -o main.exe main.c tree.c

clear:
	rm *.o *.stackdump main.exe
