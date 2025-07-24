#include <stdio.h>
#include "header.h"

int main(void) {
    printf("global vars\n");
    global_var();
    global_var();
    global_var();
    global_var();
    
    printf("static vars\n");
    static_var();
    static_var();
    static_var();
    static_var();

    printf("num types\n");
    num_types();
    casting();

    strings();
    array();

    flow();
    return 0;
}
