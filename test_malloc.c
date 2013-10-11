#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <strings.h>

int main(int argc, char *argv[]) {
	printf("Trying to malloc 64 bytes.\n");

	void *abc = malloc(64);
	
	printf("Value of abc: %p\n", abc);
	printf("\n");
	printf("Trying to malloc 128 more bytes.\n");

	void *def = malloc(128);
	
	printf("Value of def: %p\n", def);
	printf("\n");
	printf("Trying to malloc 1024 more bytes.\n");

	void *ghi = malloc(1024);
	
	printf("Value of ghi: %p\n", ghi);
	printf("\n");
	printf("Trying to malloc 1234 more bytes.\n");

	void *jkl = malloc(1234);
	
	printf("Value of ghi: %p\n", jkl);
	exit(0);
}