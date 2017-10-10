#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[255];   // Buffer variable for user input

    //TODO:
    // Get the user's name with scanf

    //TODO:
    // Print it out with printf
    printf("Write your name here: ");
    scanf("%s", buffer);
    printf("Your username is: %s\n", buffer);

    return 0;
}
