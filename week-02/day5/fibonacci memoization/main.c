#include <stdio.h>
#include <stdlib.h>

// create a function which returns a Fibonacci number like in the example code
// this time do it with memoization
// again the parameters value should be stored in a .h file

#include "number.h"

int main()
{
    fibonacci(number);
    printf("Write a number and you will get the Fibonacci value of it: ");
    scanf("%d", &number);
    printf("The number: %d Fibonacci value is: %d.", number, fibonacci());

    return 0;
}

int fibonacci()
{
    int i;
    int fibonacci[number+1];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    fibonacci[2] = 1;
    for(i = 3; i<= number; i++){
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
        return fibonacci[number];
}
