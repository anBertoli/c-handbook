#include <stdio.h>
#include "header.h"

void flow(void) {
    // ================== BLOCKS ==================
    // block can be introduced anywhere, and vars have
    // lexical scope
    int j = 4;
    {
        int j = 2;
        printf("inside block %d at pos: %p\n", j, &j);
    }
    printf("inside block %d at pos: %p\n", j, &j);


    // ================== IF ==================
    // same as other programming languages, else
    // is optional ('()' are required after if)
    int i = 5;

    if (i < 3) {
        printf("i is < than 3\n");
    } else {
        printf("i is >= than 3\n");
    }

    // blocks can be single statements with no braces
    if (i < 3)
        printf("i is < than 3\n");
    else
        printf("i is >= than 3\n");

    if (i < 3) printf("i is < than 3\n");
    else printf("i is >= than 3\n");


    // ================== FOR ==================
    for (i = 0; i < 3; i++) {
        printf("inside for %d\n", i);
    }


    // ================== WHILE/ DO WHILE ==================
    // the condition is checked before executing the block,
    // if the condition is initially false, the block is never
    // executed. The loop continues as long as the condition is true
    int f = 0;
    while (f < 10) {
        printf("inside while, i = %d\n", i);
        f++;
    }

    // the block is executed before checking the condition,
    // guarantees that the block is executed at least once.
    // The condition is checked at the end.

    // Do-while is less common but useful in specific situations
    // where you need to guarantee at least one execution
    do {
        printf("inside while, i = %d\n", i);
        f++;
    } while (f < 10);


    // ================== GOTO ==================
    // goto is a statement that jumps code execution
    // to a specific label (must start with letter)
    int k = 0;
again:
    printf("again!\n");
    k++;
    if (k < 5) goto again;

    // it's possible to do weird things (seems Basic)
    // l10: printf("hello!\n");
    // l20: goto l10;

    // if + goto can be used as building blocks
    // to build any other iteration construct
    k = 0;
loop:
    if (!(k < 10)) goto next;
    printf("loop %d\n", k);
    k++;
    goto loop;
next:

    printf("");
}
