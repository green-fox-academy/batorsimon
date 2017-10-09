#include <stdio.h>
#include <stdlib.h>

// Write a function called `sum` that sum all the numbers
// until the given parameter which you store in a .h file

#include "number.h"
int sum();

int main()
{
    printf("The numbers added together: %d \n", sum(number));
    return 0;
}

int sum(number)
{
    int i= 0;
    int j = 0;   //if i want to use factorial set it to 1

    for(i=0; i <= number; i++)  //if i want to use factorial set i to 1
    {
       // j = j * i;  //if I would like to use as  a factorial
        j += i;
    }
    return j;

}
