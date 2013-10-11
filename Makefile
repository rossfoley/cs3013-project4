all: test_malloc malloc.o

test_malloc: test_malloc.c malloc.o
	gcc -g -o test_malloc test_malloc.c malloc.o

malloc.o: malloc.c malloc.h
	gcc -g -c malloc.c -o malloc.o

clean:
	rm -rf test_malloc malloc.o *.o