#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*
write a program that decides which number is bigger
use switch-statement
*/

    int num1;
    int num2;

    num1 = 85;
    num2 = 96;

    switch(1){

    case 1: if(num1>num2){
       printf("egyes szam a nagyobb: %d", num1);
                 }
    case 2: if(num2>num1){
       printf("a masodik szam a nagyobb: %d", num2);
                  }

    }

    return 0;
}
