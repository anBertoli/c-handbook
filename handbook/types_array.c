#include <stdio.h>
#include "header.h"

// when a function receives an array as a parameter, you can use
// both [] and * notations - they are equivalent. The compiler treats
// them identically (however it may be more readable to use [])
void print_array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}

void print_array_2(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}

void array(void) {
	// ================== ARRAYS ==================
	// arrays are a list of consecutive items
	int a[5] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}

	// compiler infers length automatically
	int b[] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++) {
		printf("b[%d] = %d\n", i, b[i]);
	}

	// partial initialization (unspecified elements are 0)
	int c[5] = {10, 20}; // {10, 20, 0, 0, 0}
	for (int i = 0; i < 5; i++) {
		printf("c[%d] = %d\n", i, c[i]);
	}

	// array name represents the address of the first element
	int d[5] = {10, 20, 30, 40, 50};
	int* ptr = d; // == &d[0]

	printf("%d\n", *ptr);                    // prints 10
	printf("%d\n", *(ptr + 1));              // prints 20
	printf("%d = %d\n", ptr[2], *(ptr + 2)); // prints 30

	// when you pass an array to a function, you're actually
	// passing a pointer to the first element
	print_array(d, 5);


	// ================== LIMITATIONS ==================
	// - fixed size: once declared, you cannot change the array size (they are not vectors)
	// - bounds checking: C doesn't automatically check if you access beyond array limits
	// - no size information: functions don't automatically know how large a passed array is
	//
	// in general, they require careful attention to memory management and bounds checking.
}


void strings(void) {
	// ================== CHARS ==================
	// char are numbers (char = byte) but we can put ASCII
	// symbols (gets saved into var as related numeric code)
	// note: char max is 127, so all ASCII can be contained
	char c = 'a';
	printf("%c - %d - should be '%c'\n", c, c, 'a');
	c = 'A';
	printf("%c - %d - should be '%c'\n", c, c, 'A');

	// ================== STRINGS ==================
	// strings in C are arrays of type (signed )char, terminated
	// with 0 (NULL TERMINATOR). Needed because these are raw
	// strings, so they need a 'end signal'
	char str[6] = {'h', 'e', 'l', 'l', 'o', 0};
	printf("str = %s\n", str);
	for (int i = 0; i < 6; i++) {
		printf("str[%d] = %c (%d)\n", i, str[i], str[i]);
	}

	// we can use double quoutes as well, 0 is automatically
	// inserted at the end, or even omit the len
	char str_2[6] = "world";
	printf("str_2 = %s\n", str_2);
	char str_5[] = "ehy";
	printf("str_5 = %s\n", str_5);

	int i = 0;
	while (str_2[i] != 0) {
		printf("str_2[%d] = %c (%d)\n", i, str_2[i], str_2[i]);
		i++;
	}

	// if you specify less len than the string it will warn
	// if you specify more len than the string it will compile
	// char str_3[2] = "hello"; ---> WARNING
	// printf("str_3 = %s\n", str_3);
	char str_4[20] = "hello"; // ---> FINE, but garbage
	printf("str_4 = %s\n", str_4);

	// we can update individual chars of the strings
	char str_6[] = "hello";
	str_6[2] = 'A';
	str_6[3] = 66;
	str_6[4]++;
	printf("str_6 = %s\n", str_6);
}

