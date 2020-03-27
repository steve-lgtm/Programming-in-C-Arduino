# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wconversion
LDLIBS=-lm -lncurses

# targets


mm.o: mm.c
	$(CC) $(CFLAGS) -c mm.c $(LDLIBS) -o mm.o



# remove compiled files
clean: 
	rm -rf mm.o *.o

