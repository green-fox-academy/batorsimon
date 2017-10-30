#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Create an array of 5 integers.
 * Fill it with random integer numbers.
 * Print out the array elements in one line, divided by " | ".
 * Reverse the order of the numbers _in_the_array_ an print them out again.
 */

int main()
{
    int arr[5];
    int arr2[5];
    srand(time(NULL));

    int i = 0;
    int b = 0;

    for(i = 0; i < 5; i++) {
        int a = rand();
        arr[i] = a;
        printf("%d |", arr[i]);
    }

    printf("\n\n");

    for(i = 5; i > 0; i--) {
        b = arr[i];
        arr2[i] = b;
        printf("%d |", arr2[i]);
    }

    return 0;
}
