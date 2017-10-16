#include <stdio.h>
#include <stdlib.h>

int euclides(int number1, int number2);

int main()
{
    printf("This program finds the greatest common divisor between two numbers.\n");
    int n1 = 0;
    int n2 = 0;
    printf("Please write down a number:  \n");
    scanf("%d", &n1);
    printf("Please write down another number: \n");
    scanf("%d", &n2);
    printf("The greatest common divisor for %d and %d is: %d.\n", n1, n2, euclides(n1, n2));

    return 0;
}

int euclides(int number1, int number2)
{
    int temp = 0;
    while(number2 > 0){
        temp = number2;
        number2 = number1 % number2;
        number1 = temp;
    }
}
