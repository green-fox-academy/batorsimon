#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//TODO: write a function which returns 485 as unsigned integer value
//put your return value in an integer variable in which you should have 229, and print it out
//try to figure out which type casting you should use

int giving_back_value();

int main()
{
    int b = 0;
    b = giving_back_value();
    printf("%d\n", b);
    return 0;
}

int giving_back_value()
{
    uint32_t a = 485;
    return a;

}
