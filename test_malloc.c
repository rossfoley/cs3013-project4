#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <strings.h>

int main(int argc, char *argv[]) {
	printf("Trying to malloc 64 bytes.\n");
	void *abc = malloc(64);
	printf("Value of abc: %p\n\n", abc);

	printf("Trying to malloc 128 more bytes.\n");
	void *def = malloc(128);
	printf("Value of def: %p\n\n", def);

	printf("Trying to malloc 1024 more bytes.\n");
	void *ghi = malloc(1024);
	printf("Value of ghi: %p\n\n", ghi);

	printf("Trying to malloc 1234 more bytes.\n");
	void *jkl = malloc(1234);
	printf("Value of ghi: %p\n\n", jkl);

	printf("Freeing abc then allocating 32 bytes\n");
	printf("The address of a should be the same as the address of abc\n");
	free(abc);
	void *a = malloc(32);
	printf("Value of a: %p\n\n", a);

	printf("Trying to calloc a 32 element array of 4 bytes\n");
	void *b = calloc(32, 4);
	printf("Value of b: %p\n\n", b);

	printf("Trying to realloc def to 5000 bytes\n");
	((int *) def)[0] = 314159;
	printf("Value of def before the realloc: %d\n", ((int *) def)[0]);
	printf("Location of def before the realloc: %p\n", def);
	def = realloc(def, 5000);
	printf("Value of def after the realloc: %d\n", ((int *) def)[0]);
	printf("Location of def after the realloc: %p\n\n", def);

	printf("Trying to allocate 64 bytes\n");
	printf("This should have the same address as def\n");
	void *c = malloc(64);
	printf("Value of c: %p\n", c);
	exit(0);
}