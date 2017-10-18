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
    int a;
    a = strtol(bin_op_1, NULL, 2);
    int b;
    b = strtol(bin_op_2, NULL, 2);

    char buffer[20];
    int sum = a + b;
    itoa(sum, buffer, 2);

    printf("The binary numbers added together: %s\n", buffer);
}
