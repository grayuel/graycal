CC=gcc
CFLAGS=-Wall
all: simplecal
simplecal:
	$(CC) simplecal.c printing.c -o simplecal

clean:
	rm simplecal
