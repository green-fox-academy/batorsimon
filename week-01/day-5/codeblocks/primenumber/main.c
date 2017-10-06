#include <stdio.h>
#include <stdlib.h>


/*
Create a program which prints out oll the prime numbers
aslo add a feature where you can tell the from - to limits
for example :
from = 11;
to = 34;
output :
13, 17, 19, 23, 29, 31 , this is 6 prime numbers
*/


int main()
{
    int from;
    int to;
    int i;
    int mennyi;

    printf("Prim szamok vizsgalata!\n");
    printf("Adja meg a kezdo erteket: \n");
    scanf("%d", &from);
    printf("Adja meg a vegerteket: \n");
    scanf("%d", &to);

    for(i = from; i <= to; i++) {

            switch(i){
            case 1 : i%9 == 0;
                    continue;

            case 2 : i%8 == 0;
                     continue;
            case 3 : i%7 == 0;
                     continue;

            case 4 : i%6 == 0;
                     continue;

            case 5 : i%5 == 0;
                     continue;

            case 6 : i%4 == 0;
                     continue;

            case 7 : i%3 == 0;
                     continue;

            case 8 : i%2 == 0;
                     continue;

            case 9 : i%1 == 0;
                     printf("The prime numbers: %d \n", i);


            case 10 : i%i == 0;
                      printf("The prime numbers: %d \n", i);
            }

            printf("These are the %d numbers\n", i, mennyi);

    }


    return 0;
}
