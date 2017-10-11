#include <stdio.h>
#include <stdlib.h>

int main()
{
    //write a program which loads up fully a 50-sized integer array starting from 200 in descending order
    //but your array should contain elements which are divisible by 5 and 17
    //print out the array

    int my_array[50];

    int i = 0;
    int j = 0;

    for(i = 0; i < 50; i++) {
        for(j = 200; j >= -200; j--) {
                if(j%17==0 && j%5==0) {
                    my_array[i] = j;
                    printf("%d\n", my_array[i]);
                    }
                }
    }

    return 0;
}
