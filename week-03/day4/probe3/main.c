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


    int number1[20]; //20 sz�mjegy�
    int number2[20];

    if(point == NULL) {
        printf("%s\n", string);
        puts("No operators found");
        return(1);
    }

    while(point != NULL ) {
      printf( "%s\n", point);
      //pointot belek�ne pakolni egy egy sztringbe hogy megkpajuk a sz�mokat
      number1[10] = point;
      number2[10] = point;
      //n�velni k�ne a t�mb�k sz�m�t minden eggyes bet�r�skor
      point = strtok(NULL, s);

        //att�l f�gg�en milyen oper�tort tal�lt v�gre hajtja a k�l�nb�z� m�veleteket
        if(s == "+"){
        printf("plusz");
        }

    }

    return 0;
}
