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
    int counter;
    int prim = 0;
    int nem_prim = 0;

    printf("Prim szamok vizsgalata!\n");
    printf("Adja meg a kezdo erteket: \n");
    scanf("%d", &from);
    printf("Adja meg a vegerteket: \n");
    scanf("%d", &to);

    for(i = from; i < to; i++) {
            for(j=0; j<i; i++){
                if(j%2==0){
                    break;
                }
            }
            counter = 0;

            /* fizzbuzzos példa
            if(i%1 == 0 && i%i == 0){
                     mennyi++;
                     prim = i;
                     printf("The prime numbers: %d \n", prim);

                }

              else if(i%3==0){
            printf("Fizz\n");
              }

                else if(i%5==0){
            printf("Buzz\n");
                }

                else{
               printf("%d\n", i);
              }

              ha CSAK 2 számmal osztható akkor prim
              ha már akkor break;

              */

            }


    }
    //printf("These are the %d numbers\n", i);
    printf("The not prime numbers: %d \n", nem_prim);
    printf("These was %d prime numbers.\n", counter);



    return 0;
}
