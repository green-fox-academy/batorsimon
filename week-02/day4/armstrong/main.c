#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int a[20];
    int number = 0;
    int i = 0;
    int remain = 0;
    int power_remain = 0;
    int a = 0;
    int value_number = 0;

    printf("Write a number:");
    scanf("%d", &number);

    i = number;

    while(i != 0){
        remain = i % 10;
        value_number = value_number + remain;
        i = i / 10;
        printf("i:%d\n", i);
        printf("remain:%d\n", remain); // ezt kell majd hatványozni
        printf("value_number:%d\n", value_number);

        power_remain = (remain * remain * remain * remain);
        a ++;
        printf("a:%d\n", a);
        printf("power remain:%d\n", power_remain);
        if(power_remain * a){
             printf("\nThe %d is an Armstrong number.\n", number);
        }

    }

     printf("\nThe %d is an Armstrong number.\n", number);

    return 0;
}

