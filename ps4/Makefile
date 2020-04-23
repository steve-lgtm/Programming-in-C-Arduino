CC=gcc
CFLAGS=-std=c11 -Werror -Wall
LDLIBS=-lm
OUTPUT=crypto

all: $(OUTPUT)

$(OUTPUT): main.o bmp.o transformations.o
		cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
		$(CC) $(CFLAGS) bmp.o transformations.o main.o $(LDLIBS) -o $(OUTPUT)
		valgrind --leak-check=full ./$(OUTPUT) *.o

main.o: main.c
		$(CC) $(CFLAGS) $(LDLIBS) -c main.c -o main.o

bmp.o: bmp.c
		$(CC) $(CFLAGS) $(LDLIBS) -c bmp.c -o bmp.o

transformations.o: transformations.c
		$(CC) $(CFLAGS) $(LDLIBS) -c transformations.c -o transformations.o



clean:
		rm -rf $(OUTPUT) *.o tests
tests: tests.c
		$(CC) $(CFLAGS) tests.c $(LDLIBS) -o tests
		./tests

