#include <stdio.h>
#include "header.h"

void pointers(void) {
    // ================== POINTERS ==================
    // pointers are values that may store the mem address of
    // other variables or, more generally, store the address
    // of a mem location
    //   & to take the address of the var
    //   * to dereference pointer
    int x = 5;
    int *ptr = &x;
    printf("x = %d (ptr = %p), *ptr = %d\n", x, ptr, *ptr);

    // pointer with value zero are special: they can't be
    // used (invalid mem pointed) and also have conventional
    // meaning
    ptr = 0;
    ptr = NULL;
    printf("%d (%p)\n", x, ptr);

    // you can change value of pointer OR value of mem pointed to
    int y = 10;
    int *ptr2 = &y;
    printf("y was %d (%p)\n", y, ptr2);
    *ptr2 = 20;
    printf("y is %d (%p)\n", y, ptr2);


    // ================== ARITHMETICS ==================
    // arithmetic operations can be performed on pointers
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr_arr = arr;

    ptr_arr++;    // ptr now points to second element (20)
    ptr_arr += 2; // ptr now points to fourth element (40)
    ptr_arr--;    // ptr now points to third element (30)

    // difference between pointers
    int *ptr1 = &arr[1];
    int *ptr2 = &arr[4];
    int diff = ptr2 - ptr1; // diff = 3 (elements apart)
}


