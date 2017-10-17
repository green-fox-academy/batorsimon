#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Type in a sentence:\n\n");
    char string[256];

    //TODO: write a c program which, splits a string to words by space
	//solve the problem with the proper string.h function

    char *point;
    point = strtok(string, " ");

    if(point) {
    printf("%s\n", point);
    } else {
         point = strtok(NULL, " ");
    }

    if(point){
         printf("%s\n", point);
    }

    return 0;
}
