#include <stdio.h>
#include "header.h"


// args are passed as values/copies
// not as pointers/references
int sum(int a, int b) {
    return a + b;
}

void vars(void) {
    // declare and init together
    int a = 3;
    int b = 7;
    int c = a + b;
    printf("%d\n", c);

    // declare but init later,
    // garabge till init'ed
    int d, e, f;
    // printf("%d\n", f); var not init (rand val)
    e = 1;
    d = 2;
    f = d + e;
    printf("%d\n", f); // var init'ed (3)
}

// global variable
// lifetime: global, visibility: global
int xg;

void global_var(void) {
    xg++;
    printf("%d\n", xg);
}

void static_var(void) {
    // global variable seen only by this func
    // lifetime: global, visibility: local
    static int ss = 0;
    ss++;
    printf("%d\n", ss);
}
