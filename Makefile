CC = g++
CFLAGS = 
INCLUDE = ./include
RANLIB = ranlib

all: test

# ./lib/Matrix.o: ./src/Matrix.cpp ./src/Matrix.h
# 	$(CC) -c $< -o $@ 

# ./lib/Vector.o: ./src/Vector.cpp ./src/Vector.h
# 	$(CC) -c $< -o $@ 

# ./lib/libMatrix.a: ./lib/Vector.o
# 	ar cr $@ $^
# 	$(RANLIB) $@

test.o: test.cpp
	$(CC) -c $< -I ./src

test: test.o
	$(CC) -o $@ $<

.PHONY: clean

clean:
	rm -rf *.o ./lib/*.a ./lib/*.lib