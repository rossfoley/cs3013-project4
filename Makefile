all: meh_malloc1

meh_malloc1: meh_malloc1.c
	gcc -g -o meh_malloc1 meh_malloc1.c

clean:
	rm -rf meh_malloc1 *.o