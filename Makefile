all: test_malloc malloc

test_malloc: test_malloc.c malloc.h
	gcc -o test_malloc test_malloc.c

malloc: malloc.c malloc.h
	gcc -c malloc.c -o malloc.o

clean:
	rm -rf meh_malloc1 malloc *.o