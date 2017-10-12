#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int a[20];
    int number = 0;
    int i = 0;
    int remain = 0;
    int value_number = 0;

    printf("Write a number:");
    scanf("%d", &number);

    i = number;

    while(i != 0){
        remain = i % 10;
        value_number = value_number + remain;
        i = i / 10;
        printf("i:%d\n", i);
        printf("j:%d\n", remain);
        printf("ossz:%d\n", value_number);

    }

     printf("\nSum of digits of %d = %d\n", number, value_number);

    /*
    for(j = 0; j<=a; j++){
        if(a[j]%10==0){
            printf("%d\n", a[j]);
        }
    } */

    return 0;
}

