#include <stdio.h>
#include <stdlib.h>

/* Create a structure to represent a list of numbers. The structure should know how many number it has stored.
 * Store the numbers in an array.
 * Create functions to:
 *    * Add a new number at the end.
 *    * Get a number at a given index.
 *    * Replace a number at a given index if it exists.
 *
 * If the array is too small, create a new one, copy everything into it, add the new element and delete the old array.
 * Test in the main function whether everything works.  */

 typedef struct{
    int counter;
    int numbers[];
} numberlist;

int add_number(numberlist *arr, int number)
{
    arr->numbers[arr->counter] = number;
    arr->counter++;
}

void get_number(numberlist *arr, int index)
{
    int i = 0;
    for(i = 0; i < 20; i++){
        if(arr->numbers[i] == index){
            printf("The number is: %d in the given index is: %d\n", arr->numbers[i], index);
        }
    }

}

void replace_number(numberlist *arr, int index, int number)
{
    int i = 0;
    for(i = 0; i < 20; i++){
        if(i == index){
            printf("The number is %d in the given index is: %d\n", arr[i], index);
        }
    }

}

int main()
{

    numberlist arr[20];

    int i = 0;
    for(i = 0; i < 10; i++){
        arr->numbers[i] = i;
        arr->counter++;
    }

    add_number(numberlist arr, 5);

    for(i = 0; i < arr->counter; i++){
        printf("%d ", arr->numbers[i]);
    }

    get_number(numberlist arr, 3);

    int b = replace_number(4, 12);

    return 0;
}
