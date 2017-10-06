#include <stdio.h>
#include <stdlib.h>

//how much odd numbers are between 179 & 371
//you should be able to change the limits, like from 10 to 234
//and the program should print out the odd numbers between those two numbers
//example from 11 to 27 the program should print out:
// 13, 15, 17, 19, 21, 23, 25 this is 7 odd number between 11 and 27

int main()
{
    int i = 0;
    int j = 0;
    int l = 0;
    int m = 0;

    printf("Irjon be ket szamot amik kozott vizsgalni szeretne a paratlan szamokat!\n");
    printf("A kezdo ertek legyen: \n");
    scanf("%d", &i);
    printf("A vegertek legyen: \n");
    scanf("%d", &j);
    l = i;
    printf(" \n");

    for(i = i; i <= j; i++) {

            if(i%2!=0) {
                    printf("%d, ", i);
                    m++;
            }
    }
    printf("\nThe odd numbers between %d and %d is: %d\n", l, j,m);

    return 0;
}
