#include <stdio.h>
#include <stdlib.h>

int main()
{
    // print the even numbers till 20

    int i;

    for(i=0; i<=20; i++){
        if(i%2==0){
            printf("Paros szamok: %d\n", i);
        }
    }
    return 0;
}
