#include <stdio.h>
#include <stdlib.h>

// create a function which returns the power of a base number
//int exponent(base, power);

int main()
{
    int base = 2;
    int power = 7;

    int j = 0;
    int result = 0;

    for(j=1; j < power*power; j = j*2)
    {
        result = (base * base) * j;
        printf("%d\n", result);    //ha látni szeretném a hatványokat
    }
    printf("%d base on the power of %d is: %d\n", base, power, result);
    return 0;
}

int exponent(int i)
{


}


