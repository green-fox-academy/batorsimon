#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
 * Create a function that takes an array as argument and it's length. Determine the right data types to do this.
 * This function should order the arguments in ascending order and return this in a new sorted array.
 *
 * Create a second function that takes 3 arguments. An array, it's length and a number it is searching for.
 * The function should return the index of the number when found or -1 if it's not part of the array.
 * IMPORTANT: this function expects a sorted array and uses the strategy we used when we play guess the number.
 *
 * In the main function create an unsorted array filled with random numbers, Make it 50 long.
 * Try 2 scenarios:
 *    * In the first: You pick a random element in the unosrted array and check at which index it is after the array is sorted.
 *    * In the second: You pick a number You are sure is not in the array. Check whether the search function returns the right number.
 * Print out what You need to check these.
 */


int sorting(int *arr, int length, int *arr2)
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

    printf("The sorted array:");
    for(i = 0; i < length; i++){
        printf(" %d |", arr[i]);
        arr2[i] = arr[i];
    }
  //  return arr2;
}

int searching(int *arr2, int length, int searched)
{
    int i = 0;
    int counter = 0;

    for(i = 0; i < length; i++){
        if(arr2[i] == searched){
            printf("The searched number is in the %d. index.\n", i);
            counter++;
        }

    }
    if(counter == 0){
        printf("The searched number could not found in the array.\n");
        return -1;
    }

    return counter;
}

int main()
{
    uint32_t length = 14;
    int arr[length];

    srand(time(NULL));
    int j = 0;
    printf("The original array: ");
    for(j = 0; j < length; j++){
        int a = rand() % 100;
        arr[j] = a;
        printf("%d |", arr[j]);
    }

    printf("\n      \n");

    int arr2[length];
    sorting(arr, length, arr2);

    printf("\n");

    searching(arr2, length, 7);



    return 0;
}
