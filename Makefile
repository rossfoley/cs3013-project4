all: meh_malloc1 malloc

meh_malloc1: meh_malloc1.c
	gcc -o meh_malloc1 meh_malloc1.c

malloc: malloc.c
	gcc -c malloc.c

clean:
	rm -rf meh_malloc1 malloc *.o