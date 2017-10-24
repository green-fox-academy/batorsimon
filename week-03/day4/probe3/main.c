#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Type in a sentence:\n\n");
    char string[256];

    gets(string);

    char s[10] = " ";
    char *point;
    point = strtok(string, s);


    int number1[2]; //2 számjegy megy bele
    int number2[2];
    int i = 0;
    int j = 0;
    int c = 0;

    if(point == NULL) {
        printf("%s\n", string);
        puts("No operators found");
        return(1);
    }

    while(point != NULL ) {
      printf( "%s\n", point);
      point = strtok(NULL, s);
    }

    for(j = 0; j < 2; j++) {
        printf("\n%d\n", number1[j]);
      }

    return 0;
}
