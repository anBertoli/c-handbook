#include <stdio.h>
#include "header.h"

void print_title(char title[]) {
    printf("========================================= \n");
    printf("%s\n", title);
    printf("========================================= \n");
}


int main(void) {
    // printf("global vars\n");
    // global_var();
    // global_var();
    // global_var();
    // global_var();

    // printf("static vars\n");
    // static_var();
    // static_var();
    // static_var();
    // static_var();
    //
    // printf("num types\n");
    // num_types();
    // casting();

    // flow();

    print_title("ARRAYS");
    // strings();
    array();


    print_title("POINTERS");
    pointers();
    ptr_arithmetic();
    return 0;
}
