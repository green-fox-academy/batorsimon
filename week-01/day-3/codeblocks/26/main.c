#include <stdio.h>
#include <stdlib.h>


/*
swap the values of the to number
print out first the original values then print out the swaped values
*/
int main()
{

    int x = 32;
    int y = 20;
    printf("Eredetileg az x erteke: %d\n",x);
    printf("Eredetileg az y erteke: %d\n",y);


    int a=0;

    a=x;
    x=y;
    y=a;

    printf("Vegul az x erteke: %d\n",x);
    printf("Vegul az y erteke: %d\n",y);

    return 0;
}
