#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Type in a sentence:\n\n");
    char string[256];

    gets(string);
    char s[2] = " ";

    //TODO: write a c program which, splits a string to words by space
	//solve the problem with the proper string.h function

    char *point;
    point = strtok(string, s);

     if(point == NULL) {
        printf("%s\n", string);
        puts("No separators found");
        return(1);
     }
    while(point != NULL ) {
      printf( "%s\n", point);
      point = strtok(NULL, s);
    }

    return 0;
}
