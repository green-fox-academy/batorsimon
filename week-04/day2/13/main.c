#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *string);

int main()
{
	char my_string[50] = "Hello world!";
	//TODO: implement your own strlen function.

    int arr_length = my_strlen(my_string);
    printf("%d", arr_length);

	return 0;
}

int my_strlen(char *string)
{
    int i = 0;
    for(i = 0; string[i] != '\0'; i++){

    }
    return i;
}
