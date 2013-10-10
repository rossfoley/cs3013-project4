#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <error.h>

#define SBRK_SCALE 100
#define CHECKSUM ~0

void *malloc_head = NULL;
int malloc_buffer_size = 0;

/*
4 bytes each:
1. Free Space Size
2. Next Pointer
3. Prev Pointer
4. Used Space Size
5. Checksum
*/

void *meh_malloc(int size) {
	void *start = malloc_head;
	int malloc_size = size * SBRK_SCALE;

	if (malloc_head == NULL) {
		malloc_head = sbrk(malloc_size);

		if (malloc_head == (void *) -1) {
			return NULL;
		} else {
			malloc_buffer_size += malloc_size;
			start = malloc_head;
		}
	}

	while (((int *)start)[0] != 0) {
		// Set start to be the second 4 bytes of the current start
		// This is the pointer to the next item in the linked list
		start = (void *) ((int *) start)[1];
		if (start >= (malloc_head + malloc_buffer_size - (size + 8))) {
			if ((int) sbrk(malloc_size) == -1) {
				return NULL;
			} else {
				malloc_buffer_size += malloc_size;
			}
		}
	}

	// The first 4 bytes are the size of the memory malloc'd
	((int *) start)[0] = size;
	// The second 4 bytes are a pointer to the next chunk of memory
	((int *) start)[1] = (int) start + size + 8;

	return &((int *) start)[2];
}

void meh_free(void *abcdefg) {
	// Do nothing for now
}

int main(int argc, char *argv[]) {
	printf("Initial Values\n");
	printf("Value of malloc_head: %p\n", malloc_head);
	printf("Value of malloc_buffer_size: %i\n", malloc_buffer_size);
	printf("\n");
	printf("Trying to meh_malloc 64 bytes.\n");
	void *abc = meh_malloc(64);
	printf("Value of malloc_head: %p\n", malloc_head);
	printf("Value of malloc_buffer_size: %i\n", malloc_buffer_size);
	printf("Value of abc: %p\n", abc);
	printf("\n");
	printf("Trying to meh_malloc 128 more bytes.\n");
	void *def = meh_malloc(128);
	printf("Value of malloc_head: %p\n", malloc_head);
	printf("Value of malloc_buffer_size: %i\n", malloc_buffer_size);
	printf("Value of def: %p\n", def);
	printf("\n");
	printf("Trying to meh_malloc 1024 more bytes.\n");
	void *ghi = meh_malloc(1024);
	printf("Value of malloc_head: %p\n", malloc_head);
	printf("Value of malloc_buffer_size: %i\n", malloc_buffer_size);
	printf("Value of ghi: %p\n", ghi);
	printf("\n");
	printf("Trying to meh_malloc 1234 more bytes.\n");
	void *jkl = meh_malloc(1234);
	printf("Value of malloc_head: %p\n", malloc_head);
	printf("Value of malloc_buffer_size: %i\n", malloc_buffer_size);
	printf("Value of ghi: %p\n", jkl);
	exit(0);
}