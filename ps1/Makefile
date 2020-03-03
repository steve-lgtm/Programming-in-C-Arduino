#variables
CC=gcc
CFLAGS=-std=cll -Wall -Werror
LDLIBS=-lm
OUTPUT=ps1

#target
all: ps1

$(OUTPUT): playfair.o bmp.o main.o
        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
        gcc $(CFLAGS) playfair.o bmp.o main.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
        gcc $(CFLAGS) main.c -o main.o

playfair.o: playfair.c playfair.h
        gcc $(CFLAGS) playfair.c -o playfair.o

bmp.o: bmp.c bmp.h
        gcc $(CFLAGS) bmp.c -o bmp.o

clean:
        rm -rf $(OUTPUT) *.o

