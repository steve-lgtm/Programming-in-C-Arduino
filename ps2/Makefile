# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wconversion
LDLIBS=-lm -lncurses
OUTPUT=ps2

# targets
all: $(OUTPUT)

$(OUTPUT): k.o hof.o ui.o main.o
	$(CC) $(CFLAGS) k.o hof.o ui.o main.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LDLIBS) -o main.o

k.o: k.c k.h
	$(CC) $(CFLAGS) -c k.c $(LDLIBS) -o k.o

hof.o: hof.c hof.h
	$(CC) $(CFLAGS) -c hof.c $(LDLIBS) -o hof.o

ui.o: ui.c ui.h
	$(CC) $(CFLAGS) -c ui.c $(LDLIBS) -o ui.o


# remove compiled files
clean: 
	rm -rf $(OUTPUT) *.o

