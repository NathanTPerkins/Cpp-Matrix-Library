CC = gcc
CFLAGS = 
INCLUDE = ./include

all: ./lib/libmatrix.lib

./lib/Matrix.o: ./src/Matrix.cpp ./include/Matrix.h
	$(CC) -c $< -o $@ -I $(INCLUDE)

./lib/Vector.o: ./src/Vector.cpp ./include/Vector.h
	$(CC) -c $< -o $@ -I $(INCLUDE)

./lib/libmatrix.lib: ./lib/Matrix.o ./lib/Vector.o
	ar cr $@ $^
	ranlib $@

.PHONY: clean

clean:
	rm -rf ./lib/*.o ./lib/*.a ./lib/*.lib