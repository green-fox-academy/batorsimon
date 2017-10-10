#include <stdio.h>
#include <stdlib.h>

int main()
{
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

    printf("char_array: \n");

    int i = 0;
    for(i = 0; i < sizeof char_array; i++)
    {
        printf("%c \n", char_array[i]);
    }

    printf("\nchar_array_the_same: \n");

    int j = 0;
    for(j = 0; j < sizeof char_array; j++)
    {
        printf("%c\n", char_array[j]);
    }

	//TODO:
    // Print out the two arrays character-by-character

	//TODO:
    // What is the difference between the arrays?
    // az értékadás: elsõ karakterenként van megadva, a másik meg egyben

    return 0;
}
