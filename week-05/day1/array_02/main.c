#include <stdio.h>
#include <stdlib.h>

/*
 * Create an array of 12 integers. Fill it with random numbers.
 * Sort them in ascending order using bubble sort. -- Google it if You don't know it. (It's easy)
 * Print out the numbers before and after the sorting.
 */

int main()
{
    int arr[12];
    srand(time(NULL));

    int i = 0;
    int j = 0;
    int a = 0;

    for(i = 0; i < 12; i++) {
        int a = rand();
        arr[i] = a;
        printf("%d |", arr[i]);
    }

    printf("\n\n");

    for(i = 0; i < 11; i++){
        for(j = 0; j < 12-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                a = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = a;
            }

        }
    }

    for(i = 0; i < 12; i++){
        printf("%d |", arr[i]);
    }

    printf("\n");

    return 0;
}
