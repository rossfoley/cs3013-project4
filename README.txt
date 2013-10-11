Our program replicates the behaviour of malloc by using 12 bytes of memory to create a linked list and 8 bytes to keep track of used memory.  When memory is freed, it has the first 4 bytes of the header set back to a value that corresponds to the freed memory, so it can be allocated again by malloc.  Calloc calls malloc to allocate an array of memory as long as the parameters are correct, and realloc allocates new memory and copies the old memory to the new location.

In our program, we reference the parts of the headers with the following format:
((int *) ptr)[FREE_SIZE]
where FREE_SIZE can be replaced by any other defined constant to access the corresponding element, such as NEXT_PTR and PREV_PTR.