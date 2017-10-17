#include <stdio.h>
#include <stdlib.h>

void transform (char str[], int original_base, int new_base);

//TODO: write a program, which transforms a number from a number system to another.
//use the stdlib.h functions, and take care of error handling (see the reference)
//the transform() function should print out the result.

int main()
{
    char str[20];
    int original_base;
    int new_base;

    printf("Give me a number to transform it in an other system: ");
    scanf("%s", str);
    printf("Give me the original base: ");
    scanf("%d", &original_base);
    printf("Give me the number of the new base: ");
    scanf("%d", &new_base);

    transform(str, original_base, new_base);


    return 0;
}

void transform(char str[], int original_base, int new_base)
{
    char buffer[20];

    if(new_base == 2) {
        itoa(str, buffer, original_base);
        printf("The original value of %d is %s.\n", , original_base);
        itoa(, buffer, new_base);
        printf("The binary value of %d is %s.\n", a, new_base);
    }

}
