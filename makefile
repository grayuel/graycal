CC=gcc
CFLAGS=-Wall
all: simplecal
simplecal: simplecal.c printing.c
	$(CC) simplecal.c printing.c -o simplecal

clean:
	rm simplecal
