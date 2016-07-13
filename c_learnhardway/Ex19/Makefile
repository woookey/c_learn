CFLAGS=-Wall -g -c
CC=gcc

all: object ex19
	$(CC) ex19.o object.o -o ex19

object: object.c
	$(CC) $(CFLAGS) object.c -o object.o

ex19: ex19.c
	$(CC) $(CFLAGS) ex19.c -o ex19.o

clean:
	rm -f ex19
	rm -f *.o

test: tester.sh
	./tester.sh
