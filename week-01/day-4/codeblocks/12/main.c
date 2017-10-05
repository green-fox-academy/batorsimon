#include <stdio.h>
#include <stdlib.h>

/*
create a program which prints out the days from monday to sunday
use a loop and variables to do that
for example:
for(int i = 0; i < 6; i++){
    printf("%d\n", i);
}
you can match the numbers with the name of the days
write this program first with if and else-if statements
then do it again with switch-statement
take the conclusion:
    - which method was faster?
    - which was shorter?
    - which one did you find easier?
*/


int main()
{
    int i= 0;

    for(i=0; i < 8; i++){
        //printf("%d \n", i);
        if(i = 1){
            printf("Monday\n");
                }
        if(i = 2){
            printf("Tuesday\n");
                }
        if(i = 3){
            printf("Wednesday\n");
                }
        if(i = 4){
            printf("Thursday\n");
                }
        if(i = 5){
            printf("Friday\n");
                }
        if(i = 6){
            printf("Saturday\n");
                }
        if(i = 7){
            printf("Sunday\n");
                }


    }

  /*
    for(i=0; i < 8; i++){
            switch(i>1 && i <8){

            case 1: printf("Monday\n");

            case 2: printf("Tuesday\n");

            case 3: printf("Wednesday\n");

            case 4: printf("Thursday\n");

            case 5: printf("Friday\n");

            case 6: printf("Saturday\n");

            case 7: printf("Sunday\n");

            }

            }
            */

    return 0;
}
