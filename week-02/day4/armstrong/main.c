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
        remain = i % 10;  //digitek helyi�rt�ke
        i = i / 10;
        // value_number = value_number + remain;  // 1+6+3+4= 14    sz�mjegyek �sszege
        // printf("value_number:%d\n", value_number);
        sum_power = (int)pow(remain, length_number);  //az adott digitet a sz�m hosszus�g�ra emelem
        sum = sum_power + sum;                            //a h�tv�nyoz�s eredm�ny�t folyamatosan �sszeadom
        printf("The first digit powered: %d", sum_power);
        printf(" and added together: %d\n", sum); //ez lesz a hatv�nyoz�s v�geredm�nye
    }

    if(number == sum){
             printf("\nThe %d is an Armstrong number.\n", number);
        } else {
            printf("The %d is not an Armstrong number.\n", number);
        }
    return 0;
}


