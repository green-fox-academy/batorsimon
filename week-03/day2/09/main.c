#include <stdio.h>
#include <stdlib.h>

void binary_adder (char *bin_op_1, char *bin_op_2);

//TODO: write a program which asks for two binary numbers.
//write a function, which prints out the sum of the 2 binary numbers.

int main()
{

    char a[20];
    char b[20];

    int *bin_op1;
    bin_op1 = &a;
    int *bin_op2;
    bin_op2 = &b;

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
    int i = atoi(buffer);
    itoa(i, buffer, 2);
    printf("The binary value of %s is %s.\n", i, buffer);
}
