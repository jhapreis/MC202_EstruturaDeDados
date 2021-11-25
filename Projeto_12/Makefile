
CC     = gcc
CFLAGS = -g -Wall
header = heap.h
cfile  = heap.c

all: main

out.o: $(header) $(cfile)
	$(CC) $(CFLAGS) -c $(cfile)

main: $(cfile) main.c
	$(CC) $(CFLAGS) main.c $(cfile) -o main.exe

memory: main
	valgrind --leak-check=full ./main.exe

clear:
	rm *.o *.stackdump main.exe
