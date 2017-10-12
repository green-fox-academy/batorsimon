#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Create a function named create palindrome following your current language's style guide.
//It should take a string, create a palindrome from it and then return it.

void create_palindrome();

int main()
{
    create_palindrome();
    return 0;
}

void create_palindrome()
{
    char input[20];

    printf("Type in a word: \n");
    scanf("%s", input);
    printf("\nThe palindrome of the word is:\n%s", input);

    int i = 0;
    int j = 0;
    int input_length = strlen(input);

    for(i = input_length; i >= 0; i--) {
        printf("%c", input[i]);
        }

    /*  char temp;
    for(i = input_length,j = 0; j <= input_length; i--) {
        temp = input[i];
        input[j] = temp;
        input[j] = input[i];
        printf("%c\n", input[j]);
        j++;
    }  */
}
