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
    printf("The number is: %d and factorial of the number is: %d \n", number, factorio(number));
    return 0;
}

int factorio(number)
{
    int i = 0;
    for(i =1; i <= number; i++)
    {
        number = (number+1) * number;
    }
    return number;


}
