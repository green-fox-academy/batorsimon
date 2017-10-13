#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //int value_number = 0;
    int number = 0;
    int i = 0;
    int remain = 0;
    int sum_power = 0;
    int sum = 0;
    int length_number = 0;

    printf("Write a number:");
    scanf("%d", &number);
    i = number;

    while(i !=0){
         i = i / 10;
         length_number++;
    }
    i = number;

    while(i != 0){
        remain = i % 10;  //digitek helyiértéke
        i = i / 10;
        // value_number = value_number + remain;  // 1+6+3+4= 14    számjegyek összege
        // printf("value_number:%d\n", value_number);
        sum_power = (int)pow(remain, length_number);  //az adott digitet a szám hosszuságára emelem
        sum = sum_power + sum;                            //a hátványozás eredményét folyamatosan összeadom
        printf("The first digit powered: %d", sum_power);
        printf(" and added together: %d\n", sum); //ez lesz a hatványozás végeredménye
    }

    if(number == sum){
             printf("\nThe %d is an Armstrong number.\n", number);
        } else {
            printf("The %d is not an Armstrong number.\n", number);
        }
    return 0;
}


