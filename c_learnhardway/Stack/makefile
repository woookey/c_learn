CFLAGS =-c -Wall -g
CC = gcc

build: stack.o
	$(CC) stack.o -o program 

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c

clean:
	-rm *.o *~ program
