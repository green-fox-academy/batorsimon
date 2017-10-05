#include <stdio.h>
#include <stdlib.h>

int main()
{


    /*
create a program which generates numbers from 0 to 100
for each number write if the number is odd or even (don't print out the numbers)
*/
    int i;

    for(i=0; i<=100; i++){
        if(i%2==0){
        printf("The number is even. The number: %d\n", i);
           } else{
         printf("The number is odd.  The number: %d\n", i);
         }
    }

    return 0;
}
