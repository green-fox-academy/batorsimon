#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

/*
swap the values of the to number
print out first the original values then print out the swaped values
but this time use bitwise operators only
*/

int main()
{

//uint8_t a = 1;
    uint8_t x = 32;
    uint8_t y = 20;
    printf("Eredetileg az x erteke: %d\n",x);
    printf("Eredetileg az y erteke: %d\n",y);

    /*
    unsigned int data = 0x7654;
    data = (data ^ data & 0xff) | ((data & 0xf) << 4) | ((data & 0xf0) >> 4);
    printf("data %x \n", data);

    x = ((x & 0xf) << 4) | ((x & 0xf0) >> 4);
    */
    uint8_t a;

    a = x << 8;
    x = y << 8;
    y = a << 8;

    printf("Vegul az x erteke: %d\n",x);
    printf("Vegul az y erteke: %d\n",y);
    printf("Vegul az a erteke: %d\n",a);

    return 0;
}
