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


    int number1[20]; //20 számjegyû
    int number2[20];

    if(point == NULL) {
        printf("%s\n", string);
        puts("No operators found");
        return(1);
    }

    while(point != NULL ) {
      printf( "%s\n", point);
      //pointot belekéne pakolni egy egy sztringbe hogy megkpajuk a számokat
      number1[10] = point;
      number2[10] = point;
      //növelni kéne a tömbök számát minden eggyes betéréskor
      point = strtok(NULL, s);

        //attól függõen milyen operátort talált végre hajtja a különbözõ mûveleteket
        if(s == "+"){
        printf("plusz");
        }

    }

    return 0;
}
