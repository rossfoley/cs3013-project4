#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <error.h>

#define SBRK_SCALE 100
#define CHECKSUM ~0
#define MALLOC_OVERHEAD 20
#define USED_OVERHEAD 8
#define LINKED_LIST_OVERHEAD 12

#define FREE_SIZE 0
#define NEXT_PTR 1
#define PREV_PTR 2
#define USED_SIZE 3
#define CHECKSUM_LOC 4
#define USER_PTR 5

#define TRUE 1
#define FALSE 0

void *malloc_head = NULL;

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
	int searching = TRUE;

	if (malloc_head == NULL) {
		malloc_head = sbrk(malloc_size);

		if ((int) malloc_head == -1) {
			return NULL;
		} else {
			start = malloc_head;
			((int *) malloc_head)[0] = malloc_size - LINKED_LIST_OVERHEAD; // Set the free size
		}
	}

	while (searching) {
		if (((int *) start)[FREE_SIZE] >= size + MALLOC_OVERHEAD) {
			searching = FALSE;
		} else if ((void *) ((int*) start)[NEXT_PTR] == NULL) {
			// Now check to see if we need to sbrk again and that we are at the last linked list node
			void *next_loc = sbrk(malloc_size);

			if ((int) next_loc == -1) {
				return NULL;
			} else {
				// Since sbrk may not give us continuous memory,
				// so set up a linked list header at the new memory location
				((int *) start)[NEXT_PTR] = (int) next_loc;
				((int *) next_loc)[FREE_SIZE] = malloc_size - LINKED_LIST_OVERHEAD;
				((int *) next_loc)[NEXT_PTR] = (int) NULL;
				((int *) next_loc)[PREV_PTR] = (int) start;
			}
		} else {
			// We haven't hit the last node, so just go to the next node
			start = (void *) ((int *) start)[NEXT_PTR];
		}
	}

	// Set up the headers for the next free spot
	if (((int *) start)[NEXT_PTR] == (int) NULL) {
		void *next_header = start + size + MALLOC_OVERHEAD;
		((int *) next_header)[FREE_SIZE] = ((int *) start)[FREE_SIZE] - (USED_OVERHEAD + size);
		((int *) next_header)[NEXT_PTR] = (int) NULL;
		((int *) next_header)[PREV_PTR] = start;
	}

	// Update the headers for this allocation
	((int *) start)[FREE_SIZE] = 0;
	((int *) start)[USED_SIZE] = size;
	((int *) start)[CHECKSUM_LOC] = CHECKSUM;

	return &((int *) start)[USER_PTR];
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