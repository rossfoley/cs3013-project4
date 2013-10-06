#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <error.h>

#define SBRK_SIZE 1024
#define MAX(a,b) a > b ? a : b

void *malloc_start = NULL;

void *meh_malloc(size_t malloc_size) {
	if (malloc_start == NULL) {
		malloc_start = sbrk(MAX(malloc_size, SBRK_SIZE));
		if (malloc_start == (void *) -1) {
			return NULL;
		}
	}
}

int main(int argc, char *argv[]) {

	exit(0);
}