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
    int prim = 0;
    int nem_prim = 0;

    printf("Prim szamok vizsgalata!\n");
    printf("Adja meg a kezdo erteket: \n");
    scanf("%d", &from);
    printf("Adja meg a vegerteket: \n");
    scanf("%d", &to);

    for(i = from; i < to; i++) {

            switch(i){
            case 1 : i%9 == 0;
                     nem_prim++;

            case 2 : i%8 == 0;
                     nem_prim++;

            case 3 : i%7 == 0;
                     //continue;
                      nem_prim++;

            case 4 : i%6 == 0;
                     //continue;
                      nem_prim++;

            case 5 : i%5 == 0;
                     //continue;
                      nem_prim++;

            case 6 : i%4 == 0;
                     //continue;
                      nem_prim++;

            case 7 : i%3 == 0;
                     //continue;
                      nem_prim++;

            case 8 : i%2 == 0;
                     //continue;
                      nem_prim++;

            case 9 : i%1 == 0 && i%i == 0;
                     mennyi++;
                     prim = i;
                     printf("The prime numbers: %d \n", prim);


           // case 10 : i%i == 0;
                      //printf("The prime numbers: %d \n", i);
            }


    }
    //printf("These are the %d numbers\n", i);
    printf("The not prime numbers: %d \n", nem_prim);
    printf("These was %d prime numbers.\n", mennyi);



    return 0;
}
