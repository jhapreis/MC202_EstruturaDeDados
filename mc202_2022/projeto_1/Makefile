CC     = gcc
CFLAGS = -g -Wall
header = num_complex.h
cfile  = num_complex.c

all: main

out.o: $(header) $(cfile)
	$(CC) $(CFLAGS) -c $(cfile)

main: $(cfile) main.c
	$(CC) $(CFLAGS) main.c $(cfile) -o main.o

memory: main

	valgrind --leak-check=full ./main.o

clear:
	rm *.o *.stackdump
