CC = g++
CFLAGS = 
INCLUDE = ./include
RANLIB = ranlib

all: test

test.o: test.cpp
	$(CC) -c $< -I ./include

test: test.o
	$(CC) -o $@ $<

.PHONY: clean

clean:
	rm -rf *.o test