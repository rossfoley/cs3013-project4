all: meh_malloc1 malloc

meh_malloc1: meh_malloc1.c
	gcc -o meh_malloc1 meh_malloc1.c

malloc: malloc.c malloc.h
	gcc -c malloc.c -o malloc.o

clean:
	rm -rf meh_malloc1 malloc *.o