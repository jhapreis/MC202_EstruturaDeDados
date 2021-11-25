
CC=gcc
CFLAGS= -g -Wall

all: main

hash.o: hash.h hash.c
	$(CC) $(CFLAGS) -c hash.c

main: hash.c main.c
	$(CC) $(CFLAGS) main.c hash.c -o main.exe

memory: main
	valgrind --leak-check=full ./main.exe

clear:
	rm *.o *.stackdump main.exe
