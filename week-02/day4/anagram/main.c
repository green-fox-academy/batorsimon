#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

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
    char input[20];
    char input2[20];

    printf("Type in a word: ");
    scanf("%s", &input);

    printf("\nType an anagram of the given word: ");
    scanf("%s", &input2);

    int i = 0;
    int j = 0;
    int input_length = sizeof input / sizeof input[0];
    int input2_length = sizeof input2 / sizeof input2[0];

    for(i = 0; i < sizeof input_length; i++)
    {

        for(j = 0; j < sizeof input2_length; j++){
            if(input[i] == input2[j]){
                    printf("Megeggyezik\n");

            }

            if(sizeof input2_length > sizeof input_length) {
            printf("You typed more letters than you should!");
            exit(0);
            } else if(sizeof input2_length < sizeof input_length) {
            printf("You typed less letters than you should!");
            exit(0);
            }

        }

    }

    printf("\n\n%s %s \n", input, input2);  //plusz kell még a boolen


    /*
    printf("\n");
    printf("Type an anagram of the given word: ");

    int j = 0;
    char c2;
    int input2_length = sizeof input2 / sizeof input2[0];
    for(j = 0; j < sizeof input2_length; j++)
    {
        scanf("%c", &input2);
        input2[j] = c2;
        printf("%s", input2);
        if(sizeof input2_length > sizeof input_length) {
            printf("You typed more letters than you should!");
            exit(0);
        } else if(sizeof input2_length < sizeof input_length) {
            printf("You typed less letters than you should!");
            exit(0);
        }
    }
    */


}
