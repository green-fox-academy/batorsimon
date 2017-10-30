#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/*
 * Create a function that takes an array of integers as an argument (a pointer) and it's length as an unsigned integer.
 * The function should sort the elements of the array in ascending order.
 *
 * Print it out before and after to be able to check whether it works as supposed.
 */


void func(int *arr, int length)
{
    int i = 0;
    int j = 0;
    int a = 0;
    for(i = 0; i < length; i++){
        for(j = 0; j < length-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                a = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = a;
            }

        }
    }

    for(i = 0; i < length; i++){
        printf("%d |", arr[i]);
    }

}

int main()
{
    uint32_t length = 14;
    int arr[length];

    srand(time(NULL));
    int j = 0;
    for(j = 0; j < length; j++){
        int a = rand() % 100;
        arr[j] = a;
        printf("%d |", arr[j]);
    }

    printf("\n-------------\n");

    func(arr, length);

    return 0;
}
