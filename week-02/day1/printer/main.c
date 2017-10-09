#include <stdio.h>
#include <stdlib.h>

// Create a function called `printer`
// which prints the input parameters
// can have multiple number of arguments
// store your variables in a .h file

#include "print.h"
int printer();

int main()
{
    printer();
    return 0;
}

int printer(print)
{
    printf(" %d\n %d\n %d\n %d\n", number1, number2, number3, number4);
}
