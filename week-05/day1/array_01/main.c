#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Create an array of 5 integers, fill it with random numbers.
 * Create an other of 7 integers.
 * Copy the contents of the first array into the second one in a way,
 * that the first and the last numbers of the second array are both 42,
 * and it contains all the elements of the first array.
 */

int main()
{
    int arr[5];
    int arr2[7];

    srand(time(NULL));
    int i = 0;
    int a = 0;
    for(i = 0; i < 5; i++) {
        int a = rand();
        arr[i] = a;
        printf("%d |", arr[i]);
    }

    printf("\n\n");

    arr2[0] = 42;

    for(i = 0; i < 6; i++){
        arr2[i+1] = arr[i];
    }

    arr2[6] = 42;
    for(i = 0; i < 7; i++)
        printf("%d |", arr2[i]);


    return 0;
}
