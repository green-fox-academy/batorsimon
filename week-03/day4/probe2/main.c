#include <stdio.h>
#include <ctype.h>

typedef char * string;

int main(int argc, char *argv[])
{
   // string inputS = "23+23 + 23 / 2 = 232424";
    //string inputS[20];

    string inputS;
    char array1[20];
    inputS = array1;

    string input[50];   /* token stückzahl */
    char   buffer[200];
    int    i;
    int    strnum = 0;
    char  *next = buffer;
    char   c;

    printf("Write: \n");
    scanf("%s", array1);
    //gets(inputS);
    printf("input: %s\n", inputS);
    printf("parsing:\n");

    while ((c = *inputS++) != '\0')
    {
        input[strnum++] = next;
        if (isdigit(c))
        {
            printf("Digit: %c\n", c);
            *next++ = c;
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


    return 0;
}
