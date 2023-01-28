CC = g++
CFLAGS = -L ../../lib -lmatrix
INCLUDE = ../../include

all: test

test.o: test.cpp
	$(CC) -c $< -o $@ -I $(INCLUDE)

test: test.o
	$(CC) $< -o $@ $(CFLAGS)


.PHONY: clean

clean:
	rm -rf *.o test