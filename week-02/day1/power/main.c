#include <stdio.h>
#include <stdlib.h>

// create a function which returns the power of a base number
//int exponent(base, power);

int exponent(int base1, int power1);

int main()
{
    int base = 2;
    int power = 7;
    int ret;

    ret = exponent(base, power);

    return 0;
}

int exponent(int base1, int power1)
{

    int a = 1;
    int j = 0;
    int result = 1;

    for(j=power1; j > 0; )
    {
        a = (base1 * base1)/2;
        result = a * result;
        printf("%d\n", result);
        j--;
    }
    printf("%d base on the power of %d is: %d\n", base1, power1, result);
    return result;
}


