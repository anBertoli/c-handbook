#include <stdio.h>
#include <limits.h>
#include "header.h"

void num_types(void) {

	// ================== NUM TYPES

    // signed integer, +/-
    char sc = 2;         // 1 byte usually (platform-dependant)
    short int si = -4;   // 2 byte usually (platform-dependant)
    int i = -4;         // 4 byte usually (platform-dependant)
    long int li = -456;  // 4/8 byte usually (platform-dependant)
    long long int lli = -456;  // 8 byte usually (platform-dependant)

    // unsigned integer, +/0
    unsigned char uc = 3;
    unsigned short us = 3;
    unsigned int ui = 3;
    unsigned long int uli = 3;
    unsigned long long int ulli = 3;

    // decimal, +/-
    float f = 1.23456; // single precision, typically 4 bytes
    double d = 1.23456; // double precision, typically 8 bytes
    long double ld = 1.23456; // extended precision, varyes

    // overflows
    // - defined for unsigned integers
    // - UB for signed integers

    // ================== LIMITS
    // The C standard guarantees minimum sizes but allows implementations to use larger sizes:
    // - char is exactly 1 byte
    // - short ≥ 2 bytes
    // - int ≥ 2 bytes (but typically 4)
    // - long ≥ 4 bytes
    // - long long ≥ 8 bytes
    //
    // The relationship sizeof(char) ≤ sizeof(short) ≤ sizeof(int) ≤ sizeof(long) ≤ sizeof(long long) is always maintained.

    // You can determine the exact size of types on your system using
    // the sizeof operator or by including <limits.h> and <float.h>
    // for detailed information about ranges and precision.
    // For example, for this specific platform:
    printf("signed char len: %lu\n", sizeof(sc));
    printf("signed short len: %lu\n", sizeof(si));
    printf("signed int len: %lu\n", sizeof(i));
    printf("signed long int len: %lu\n", sizeof(li));
    printf("signed long long int len: %lu\n", sizeof(lli));

    printf("unsigned char len: %lu\n", sizeof(uc));
    printf("unsigned short len: %lu\n", sizeof(us));
    printf("unsigned int len: %lu\n", sizeof(ui));
    printf("unsigned long int len: %lu\n", sizeof(uli));
    printf("unsigned long long int len: %lu\n", sizeof(ulli));

    printf("float len: %lu\n", sizeof(f));
    printf("double len: %lu\n", sizeof(d));
    printf("long double len: %lu\n", sizeof(ld));

    // Per vedere limiti: #include <limits.h>
    printf("range of short: from %d to %d\n", INT_MIN, INT_MAX);
    printf("range of int: from %d to %d\n", INT_MIN, INT_MAX);
    printf("range of unsigned int: from 0 to %u\n", UINT_MAX);
    printf("range of long: from %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("bits per char: %d\n", CHAR_BIT);


	// ================== STANDARD NUM TYPES ==================
	// new types have been added via the <stdint.h>
	// which have fixed bytes size
	#include <stdint.h>
	uint8_t my_u8 = 20; // unsigned, 1 byte
    // ...
	uint64_t my_u64 = 200; // unsigned, 8 bytes

	int8_t my_i8 = 10; // signed, 1 byte
    // ...
	int64_t my_i64 = 200; // signed, 8 bytes

	// can contain size of pointer (signed supports ptr math)
	uintptr_t my_u_ptr = 200;
	intptr_t my_i_ptr = 200;

	printf("len uint8_t: %lu\n", sizeof(my_u8));
	printf("len uint64_t: %lu\n", sizeof(my_u64));
	printf("len int8_t: %lu\n", sizeof(my_i8));
	printf("len int64_t: %lu\n", sizeof(my_i64));
	printf("len uintptr_t: %lu\n", sizeof(my_u_ptr));
	printf("len intptr_t: %lu\n", sizeof(my_i_ptr));
}

void casting(void) {

    // ================== IMPLICIT
    // - when passing as arg: int fn(a int); char i = 1; fn(i);
    // - expressions: char c = 127; int i = c + 1;

	// ================== EXPLICIT
    int i = 4;
    long int li = (long int)i;

    printf("len i: %lu\n", sizeof(i));
    printf("len li: %lu\n", sizeof(li));
}


