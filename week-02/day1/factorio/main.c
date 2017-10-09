#include <stdio.h>
#include <stdlib.h>


// create a function called `factorio`
// that returns it's input's factorial with and without recursion
// again the parameters value should be stored in a .h file
//
#include "number.h"
int factorio();

int main()
{
    printf("The given number is: %d and factorial of the number is: %d \n", number, factorio(number));
    return 0;
}

int factorio(number)
{
    int i = 0;
    int j = 1;

    for(i =1; i <= number; i++)
    {
        j = j * i;
    }
    return j;


}
