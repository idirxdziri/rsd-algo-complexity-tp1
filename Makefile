CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic

.PHONY: all test clean

all: primalite

primalite: primalite.c primalite.h main.c
	$(CC) $(CFLAGS) primalite.c main.c -o primalite

clean:
	rm -f primalite *.o
