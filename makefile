CC=gcc
CFLAGS=-Wall
all:graycal
graycal:
	$(CC) main.c makeOutput.c weeksOutput.c calculateMonth.c printOutput.c leapYear.c -o graycal

clean:
	rm graycal
