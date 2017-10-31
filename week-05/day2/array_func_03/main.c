#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Create a function that takes an array of array of characters and returns an array of integers each representing the
 * lenght of the given character array in the first array.
 * Say your input is this: {"Good", "Morning", "Vietnam"}
 * Your output should be this: {4, 7, 7}.
 * HINT: strings are terminated with a special character: '\0'.
 * So, "Good" as an array of characters would look like this: {'G', 'o', 'o', 'd', '\0'}.
 *
 * In the main function create code that demonstrates that Your function works approrpiately.
 */

int *arr_length(char *arr1, char *arr2, char *arr3)
{
    int arr1_1 = strlen(arr1);
    int arr2_2 = strlen(arr2);
    int arr3_3 = strlen(arr3);

    int arr_ossz[3] = {arr1_1, arr2_2, arr3_3};
    return arr_ossz;
}

int main()
{
    char arr1[] = {"Good"};
    char arr2[] = {"Morning"};
    char arr3[] = {"Vietnam"};

    int *length;
    length = arr_length(arr1, arr2, arr3);

    int i = 0;
    for(i = 0; i < 3; i++) {
        printf("%d, ", *(length + i));
    }

    return 0;
}
