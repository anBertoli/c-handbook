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
}

void ptr_arithmetic(void) {
    // ================== ARITHMETICS ==================
    // arithmetic operations can be performed on pointers
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr_arr = arr;
    printf("arr[0] = %d = %d (%p)\n", arr[0], ptr_arr[0], ptr_arr);

    // we can increase the pointer, note that +n is
    // treated as = ptr + n*sizeof(*ptr), or in other
    // words: 'go to mem address equal to base plus
    // n times the size of the pointed type'

    ptr_arr++;    // ptr now points to second element (20) --> *ptr_arr == ptr_arr[1]
    ptr_arr += 2; // ptr now points to fourth element (40) --> *ptr_arr == ptr_arr[3]
    ptr_arr--;    // ptr now points to third element (30)  --> *ptr_arr == ptr_arr[2]

    // note that pointer add/sub works similarly to array
    // indexing, meaning: the operation 'ptr+n' is equivalent
    // to ptr[n], both will jump the position
    //   - ptr + n*sizeof(*ptr)
    //
    // the difference is that array indexing also dereferences
    // the pointer, while ptr math keeps the value as a ptr
    char mystr[] = "AABBCCDDEEFF";
    char *str_ptr = mystr;
    printf("mystr = %s (%p), str_ptr = %s (%p)\n", mystr, mystr, str_ptr, str_ptr);
    printf("mystr[4] = %s (%p), str_ptr+4 = %s (%p)\n", &mystr[4], &mystr[4], str_ptr + 4, str_ptr + 4);
    printf("mystr[2] = %s (%p), str_ptr+2 = %s (%p)\n", &mystr[2], &mystr[2], str_ptr + 2, str_ptr + 2);

    // if the type of the pointer is different from the actual
    // data in the array jumps will be unaligned with underlying
    // data. Following examples prints:
    //  - mystr[2]  =       BBCCDDEEFF   --> jumps to sizeof(char)*2  = +2
    //  - *(str_ptr+2) =    CCDDEEFF     --> jumps to sizeof(short)*2 = +4

    char mystr_2[] = "AABBCCDDEEFF";    // 1 byte long
    short *str_ptr_2 = (short*)mystr_2; // 2 bytes long
    printf("base pointer: mystr = %p, str_ptr = %p\n", mystr_2, str_ptr_2);
    printf(
        "(unaligned) mystr[2] = %s (%p), str_ptr+2 = %s (%p)\n",
        &mystr_2[2], &mystr_2[2], (char*)(str_ptr_2 + 2), str_ptr_2 + 2
    );

    // is possible to do the difference between pointers,
    // where a difference is computed as the number of vals
    // of the pointed type there are
    int *ptr1 = &arr[1];
    int *ptr2 = &arr[4];
    int diff = ptr2 - ptr1; // diff = 3 (elements apart)
    printf("ptr1: %p, ptr2: %p, diff is %d\n", ptr1, ptr2, diff);
}

