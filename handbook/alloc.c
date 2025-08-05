#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void allocation(void) {
    // ================== ALLOCATION ==================
    // malloc allocates a block of memory on the heap and
    // returns a pointer to the first byte of that memory.
    // The allocated memory is not initialized, so it contains
    // random values. Memory must be manually freed after
    // usage,every malloc call must be paired with a free()
    // call to avoid memory leaks.

    // void* malloc(size_t size)
    // - size is the # of bytes to allocate
    // - returns: void* pointer to allocated memory, or NULL if allocation fails
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("error: allocation failed\n");
        return;
    }

    *ptr = 42;
    printf("Value: %d\n", *ptr);

    free(ptr); // free the memory!!

    // alternatives are
    // - calloc(): allocates and initializes to zero
    // - realloc(): resizes an already allocated block


    // ARRAY ALLOCATION
    // whatever type can be allocated, including arrays,
    // in this case an array of 10 values (integers)
    int *array = (int*)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        array[i] = i * i;
    }
    free(array);


    // COMMON ERRORS
    // - memory leaks: forgetting to call free()
    // - double free: calling free() twice on the same pointer
    // - use after free: using memory after freeing it
    // - buffer overflow: writing beyond the allocated memory bounds
}
