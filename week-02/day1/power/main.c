#include <stdio.h>
#include <stdlib.h>

// create a function which returns the power of a base number
//int exponent(base, power);

int exponent(int power);

int main()
{
    int base = 2;
    int power = 7;

    int exponent();
    print("%d", exponent(result));

    return 0;
}

int exponent(int power)
{
    int base = 2;
    //int power = 7;

    int a = 1;
    int j = 0;
    int result = 1;

    for(j=power; j > 0; )
    {
        a = (base * base)/2;
        result = a * result;
        printf("%d\n", result);
        j--;
    }
    printf("%d base on the power of %d is: %d\n", base, power, result);
    return result;




}


