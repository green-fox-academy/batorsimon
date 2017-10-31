#include <stdio.h>
#include <stdlib.h>

/*
 * Create a function that takes an array of array of characters and returns an array of integers each representing the
 * lenght of the given character array in the first array.
 * Say your input is this: {"Good", "Morning", "Vietnam"}
 * Your output should be this: {4, 7, 7}.
 * HINT: strings are terminated with a special character: '\0'.
 * So, "Good" as an array of characters would look like this: {'G', 'o', 'o', 'd', '\0'}.
 *
 * In the main function create code that demonstrates that Your function works approrpiately.

 char arr[] = "The";
    char arr2[] = "Quick";
    char arr3[] = "brown";
    char arr4[] = "Dog";
    char arr5[] = "jumps";
    char arr6[] = "over";
    char arr7[] = "the";
    char arr8[] = "lazy";
    char arr9[] = "fox";

    char *pointers2[9];
    pointers2[0] = arr;
    pointers2[1] = arr2;
    pointers2[2] = arr3;
    pointers2[3] = arr4;
    pointers2[4] = arr5;
    pointers2[5] = arr6;
    pointers2[6] = arr7;
    pointers2[7] = arr8;
    pointers2[8] = arr9;

 */

int arr_length(arrs, length)
{
    return 0;

}

int main()
{

    char arr1[] = {"Good"};
    char arr2[] = {"Morning"};
    char arr3[] = {"Vietnam"};

    int length[4];

    char arrs[3] = {
        arrs[0] = arr1,
        arrs[1] = arr2,
        arrs[2] = arr3
    };

    arr_length(arrs, length);
    return 0;
}
