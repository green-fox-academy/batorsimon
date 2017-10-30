#include <stdio.h>
#include <stdlib.h>

/*
 * Create 9 arrays of characters, each should contain a word.
 * Let it be this: The Quick brown Dog jumps over the Lazy Fox.
 * Create an array of 9 pointers of chractrer type.
 * Make it so, that each pointer points to one of the words.
 * Print them out, each in a new line using this array of pointers.
 * Now make it so, that the Fox is Green and he jumps over the lazy dog.
 * Use the existing arrays to achive this.
 * Print it out again.
 */

int main()
{
    char arr[] = "The";
    char arr2[] = "Quick";
    char arr3[] = "brown";
    char arr4[] = "Dog";
    char arr5[] = "jumps";
    char arr6[] = "over";
    char arr7[] = "the";
    char arr8[] = "lazy";
    char arr9[] = "fox";

    char *pointers[] = {
        "The",
        "Quick",
        "brown",
        "Dog",
        "jumps",
        "over",
        "the",
        "lazy",
        "fox"
    };

    int i = 0;
    for(i = 0; i < 9; i++) {
        printf("%s\n", pointers[i]);
    }

    return 0;
}
