#include <stdio.h>
#include <ctype.h>

typedef char * string;

int main(int argc, char *argv[])
{
   // string inputS = "23+23 + 23 / 2 = 232424";

    string inputS;
    char array1[20];
    inputS = array1;

    string input[50];   /* token stückzahl */
    char   buffer[200];
    int    i;
    int    strnum = 0;
    char  *next = buffer;
    char   c;

    int number1;
    char number2[20];
    int k = 0;
    int j = 0;

    printf("Write: \n");
    scanf("%s", array1);
    printf("input: %s\n", inputS);
    printf("parsing:\n");

    while ((c = *inputS++) != '\0')
    {
        input[strnum++] = next;
        if (isdigit(c))
        {
            printf("Digit: %c\n", c);
            *next++ = c;

            for(k = 0; k < 20; k++) {
                number1=c;  //belekéne rakni a tömbe a digiteket hogy egy szám legyen
            }

             while (isdigit(*inputS))
            {
                c = *inputS++;
                printf("Digit: %c\n", c);
                *next++ = c;
            }
            *next++ = '\0';
        }
        else
        {
            printf("Non-digit: %c\n", c);
            *next++ = c;
            *next++ = '\0';

        }
    }

    /*
    for(j = 0; j < 20; j++) {
        printf("%c", number1[j]);
    } */
    printf("%d", number1);


    return 0;
}
