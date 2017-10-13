#include <stdio.h>
#include <stdlib.h>

// create a function which returns a Fibonacci number like in the example code
// this time do it with memoization
// again the parameters value should be stored in a .h file

#include "number.h"

//int fibonacci(number);

int main()
{
    fibonacci();
    return 0;
}

int fibonacci(number)
{
    if (number <= 2)
        return 1;
    else
        return fibonacci(number - 1) + fibonacci(number - 2);
}
