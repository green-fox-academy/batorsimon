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
    numberlist.numbers[numberlist.counter] = number;
    numberlist.counter++;
}

void get_number(numberlist *arr)
{
    int index = 1;
    int i = 0;
    for(i = 0; i < 20; i++){
        if(i == index){
            printf("The number is %d in the given index is: %d\n", numberlist.numbers[i], index);
        }
    }

}

void replace_number(numberlist *arr)
{
    int index = 1;
    int i = 0;
    for(i = 0; i < 20; i++){
        if(i == index){
            printf("The number is %d in the given index is: %d\n", arr[i], index);
        }
    }

}

int main()
{
    int i = 0;
    for(i = 0; i < 10; i++){
        numberlist.numbers[i] = i;
        numberlist.counter++;
    }

    add_number(numberlist arr, 5);

    for(i = 0; i < numberlist.counter; i++){
        printf("%d ", numberlist.numbers[i]);
    }

    int a = get_number(numberlist arr, 3);

    for(i = 0; i < numberlist.counter; i++){
        printf("%d ", numberlist.numbers[i]);
    }

    int b = replace_number(numberlist arr, 4, 12);

    for(i = 0; i < numberlist.counter; i++){
        printf("%d ", numberlist.numbers[i]);
    }


    return 0;
}
