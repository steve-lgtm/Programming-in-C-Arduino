CC=gcc
CFLAGS=-std=c11 -Werror -Wall
LDLIBS=-lm
OUTPUT=crypto

all: $(OUTPUT)

$(OUTPUT): main.o game.o backpack.o command.o container.o item.o parser.o room.o world.o
		cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
		$(CC) $(CFLAGS) main.o game.o backpack.o command.o container.o item.o parser.o room.o world.o $(LDLIBS) -o $(OUTPUT)
		valgrind --leak-check=full ./$(OUTPUT) *.o

main.o: main.c
		$(CC) $(CFLAGS) $(LDLIBS) -c main.c -o main.o

game.o: game.c
		$(CC) $(CFLAGS) $(LDLIBS) -c game.c -o game.o

backpack.o: backpack.c
		$(CC) $(CFLAGS) $(LDLIBS) -c backpack.c -o backpack.o

command.o: command.c
		$(CC) $(CFLAGS) $(LDLIBS) -c command.c -o command.o

container.o: container.c
		$(CC) $(CFLAGS) $(LDLIBS) -c container.c -o container.o

item.o: item.c
		$(CC) $(CFLAGS) $(LDLIBS) -c item.c -o item.o

parser.o: parser.c
		$(CC) $(CFLAGS) $(LDLIBS) -c parser.c -o parser.o

room.o: room.c
		$(CC) $(CFLAGS) $(LDLIBS) -c room.c -o room.o

world.o: world.c
		$(CC) $(CFLAGS) $(LDLIBS) -c world.c -o world.o
clean:
		rm -rf $(OUTPUT) *.o tests
tests: tests.c
		$(CC) $(CFLAGS) tests.c $(LDLIBS) -o tests
		./tests

