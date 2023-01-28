CC = gcc
CFLAGS = -W
INCLUDE = ./include

all: ./lib/libmatrix.a

./lib/Matrix.o: ./src/Matrix.cpp ./include/Matrix.hpp
	$(CC) -c $< -o $@ -I $(INCLUDE) -W

./lib/libmatrix.a: ./lib/Matrix.o
	ar cr $@ $<
	ranlib $@

.PHONY: clean

clean:
	rm -rf ./lib/*.o ./lib/*.a ./lib/*.lib