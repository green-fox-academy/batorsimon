#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Write a C program to find the two largest element in an array using only 1 for loop
// From <limits.h> use INT_MIN: this is the least integer
int main()
{
    int number_array[8] = {48, 59, 2, -8, 55, 56, 78, 12};
    int i = 0;
    int max1 = INT_MIN;
    int max1_place = 0;
    int max2 = INT_MIN;
    int max2_place = 0;
    int array_length = sizeof number_array / sizeof number_array[0];
    printf("The members in the given array are: \n");
    for(i = 0; i < array_length; i++) {
        printf("%d\n", number_array[i]);
        if(number_array[i] > max1) {
            max1_place = i+1; //gives the index value of the biggest number
            max2 =  max1;
            max1 = number_array[i];
        } else if(number_array[i] < max1 & number_array[i] > max2) {
            max2_place = i+1;
            max2 = number_array[i];
        }
    }
    printf("\nThe biggest number is: %d.\n", max1);
    printf("The biggest number is in the %d. place in the array.\n", max1_place);
    printf("The second biggest number is: %d.\n", max2);
    printf("The second biggest number is in the %d. place in the array.\n", max2_place);
    return 0;
}
