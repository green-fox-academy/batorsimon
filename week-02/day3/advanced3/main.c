#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[20];
    int freq[20]; // jelolotomb
    // TODO: write a program which asks for a number,
    // that will be the real size of the array (20 elements are allocated, that's the maximum size)
    // Then load up the array with integer values. Finally print all unique elements in array
    int size_of_arr = 0;
    int numbers_in_arr = 0;
    int arr_length = sizeof arr / sizeof arr[0];
    int c = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    //int b = rand();

    printf("Write a number between 1 and 20, which will be the size of your array: ");
    scanf("%d", &size_of_arr);

    if(size_of_arr > 20 | size_of_arr<=0){
        printf("Number isnt between the argument!");
        exit(0);
    }

    printf("Write numbers between the given range: \n");

    for(j = 1; j < size_of_arr; j++){
       scanf("%d\n", &numbers_in_arr);
       arr[j] = numbers_in_arr;
    }

    printf("Now lets see which of the given numbers were unique: \n");

    for(i = 1; i < size_of_arr; i++) {
        printf("%d\n", arr[i]);
        c = arr[i];

        if(i == c) {
            printf("%d\n", c);
            }
    }


    return 0;
}
