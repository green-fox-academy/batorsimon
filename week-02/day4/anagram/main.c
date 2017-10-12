#include <stdio.h>
#include <stdlib.h>

//Create a function named is anagram following your current language's style guide.
//It should take two strings and return a boolean value depending on whether its an anagram or not.

void anagram();

int main()
{
    anagram();
    return 0;
}

void anagram()
{
    char input[20] = {0};
    char input2[20] = {0};

    printf("Type in a word: ");
    scanf("%s", &input);

    printf("\nType an anagram of the given word: ");
    scanf("%s", &input2);

    int i = 0;
    int j = 0;
    int input_length = sizeof input / sizeof input[0];
    int input2_length = sizeof input2 / sizeof input2[0];

    if(input_length < input2_length) {
            printf("You typed more letters than you should!");
            exit(0);
            } else if(input_length > input2_length ) {
            printf("You typed less letters than you should!");
            exit(0);
            }

    for(i = 0; i < input_length; i++){
            printf("%c\n", input[i]);

    }



/*
    for(i = 0; i < input_length; i++)
    {
        for(j = 0; j < input2_length; j++) {
            if(input[i] == input2[j]){

                    printf("True\n");

            } else{
            printf("False!\n");
            }

            if(input_length < input2_length) {
            printf("You typed more letters than you should!");
            exit(0);
            } else if(input_length > input2_length ) {
            printf("You typed less letters than you should!");
            exit(0);
            }

        }

    }  */

}
