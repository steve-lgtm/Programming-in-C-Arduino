CC=gcc
CFLAGS=-std=c11 -Werror -Wall
LDLIBS=-lm
OUTPUT=crypto

all: $(OUTPUT)

$(OUTPUT): main.o hof.o k.o ui.o
		cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
		$(CC) $(CFLAGS) hof.o k.o ui.o main.o $(LDLIBS) -o $(OUTPUT)
		valgrind --leak-check=full ./$(OUTPUT) *.o

main.o: main.c
		$(CC) $(CFLAGS) $(LDLIBS) -c main.c -o main.o

hof.o: hof.c
		$(CC) $(CFLAGS) $(LDLIBS) -c hof.c -o hof.o

k.o: k.c
		$(CC) $(CFLAGS) $(LDLIBS) -c k.c -o k.o

ui.o: ui.c
		$(CC) $(CFLAGS) $(LDLIBS) -c ui.c -o ui.o

clean:
		rm -rf $(OUTPUT) *.o tests
tests: tests.c
		$(CC) $(CFLAGS) tests.c $(LDLIBS) -o tests
		./tests

