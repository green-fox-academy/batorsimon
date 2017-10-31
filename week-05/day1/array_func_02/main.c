#include <stdio.h>
#include <stdlib.h>

/*
 * Create a function that takes two arrays of characters and a number.
 * It should replace the contents of the first array from the given index
 * with the contents of the second array.
 * The function should return a number which tells whether it was successful:
 *    * If all is right it should return 0.
 *    * If the index is out of bounds it should return -1.
 *    * If the inserted content would be longer than the receiving array it should return 1 and leave the array as it is.
 * IMPORTANT: Think about what kind of arguments You need to make this happen and craft the function accordingly.
 *
 * Write code in the main function to test all scenarios and write out the result You need to check whether this works.
 */

int index_swap(char *arr1, char *arr2, int *number)
{
    int i = 0;
    for(i = 0; i < 6; i++) {
        if(i == number) {
            arr1[i] = arr2[i];
            return 0;
        }

    }

}

int main()
{
    char arr1[6] = {'a','b','c','d','e','f'};
    char arr2[6] = {'x','y','z','w','b','s'};

    int i = 0;
    for(i = 0; i < 6; i++) {
        printf("Arr1 %d. element: %c\n", i, arr1[i]);
    }
    printf("------------------------------\n");
     for(i = 0; i < 6; i++) {
        printf("Arr2 %d. element: %c\n", i, arr2[i]);
    }
    printf("------------------------------\n");

    index_swap(*arr1, *arr2, 4);

    return 0;
}
