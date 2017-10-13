#include <stdio.h>
#include <stdlib.h>

// create a function to calculate factorial of a number using recursion

int factorial(int number)
{
    if(number <= 1) {
      return 1;
    }
    return number * factorial(number-1);

}

int main()
{
    int number = 7;
    printf("The factorial of %d is %d.\n", number,factorial(number));

    return 0;
}

