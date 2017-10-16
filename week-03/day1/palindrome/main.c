#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void  palindrome(char input);

int main()
{
	char input[100];
	printf("please enter a word: \n");
	scanf("%s", input);

	palindrome(input[100]);

	return 0;
}

void  palindrome(char input)
{

	char pointer;
	int i = 0;

	for (i; i < strlen(input); i++) {
        pointer = input[i];
        printf("%s", input[i]);


		printf("%c", pointer);
	}
}
