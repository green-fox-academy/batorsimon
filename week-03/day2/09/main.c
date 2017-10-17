#include <stdio.h>
#include <stdlib.h>

void binary_adder (char *bin_op_1, char *bin_op_2);

//TODO: write a program which asks for two binary numbers.
//write a function, which prints out the sum of the 2 binary numbers.

int main()
{

    char a[20];
    char b[20];


    printf("Give me a binary number: ");
    scanf("%s", a);
    printf("Give me another binary number: ");
    scanf("%s", b);

    binary_adder(a, b);

    return(0);
}

void binary_adder (char *bin_op_1, char *bin_op_2)
{
    char buffer[20];
    int a = atoi(str);

    if(new_base == 2) {
        itoa(a, buffer, new_base);
        printf("The binary value of %s is %s.\n", str, buffer);
    }
    int c = 0, b = 0, a = 0;
    a+b;
    printf("The number %d and %d added together is: %d", a, b, c);
}
