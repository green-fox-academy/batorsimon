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

    int i = 0;
/*
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

    for(i = 0; i < 9; i++) {
        printf("%s\n", pointers[i]);
    }
*/
    printf("-------------------------\n");

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

    for(i = 0; i < 9; i++) {
        printf("%s\n", pointers2[i]);
    }

    printf("-------------------------\n");

    char *pointers3[11];
    pointers3[0] = arr;
    pointers3[1] = arr2;
    pointers3[2] = "Green";
    pointers3[3] = arr9;
    pointers3[4] = arr5;
    pointers3[5] = arr6;
    pointers3[6] = arr7;
    pointers3[7] = arr8;
    pointers3[8] = arr4;

    for(i = 0; i < 9; i++) {
        printf("%s\n", pointers3[i]);
    }

    return 0;
}
