#include <stdio.h>
#include <stdlib.h>


/*
create a program which draws a diamond, like this:
123456*123456
1234* * *1234
12* * * * *12
* * * * * * *
* * * * * * *
12* * * * *12
1234* * *1234
123456*123456

(6* 8) +1 oszlop teli + (6*8)


*/


int main()
{
    int bevitel=0, c=0, k=0, space = 1;

    printf("Enter number of rows\n");
    scanf("%d", &bevitel);

    space = bevitel - 1;

    for (k = 1; k <= bevitel; k++)
    {
    for (c = 1; c <= space; c++)
      printf(" ");

    space--;

    for (c = 1; c <= 2*k-1; c++)
        printf("*");

    printf("\n");
    }

    space = 1;

    for (k = 1; k <= bevitel - 1; k++)
    {
    for (c = 1; c <= space; c++)
      printf(" ");

    space++;

    for (c = 1 ; c <= 2*(bevitel-k)-1; c++)
      printf("*");

    printf("\n");
    }


    return 0;
}
