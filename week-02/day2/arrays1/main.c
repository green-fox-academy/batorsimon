#include <stdio.h>
#include <stdlib.h>

int main()
{
    char my_name_array[] = "Simon Bator";
    int i = 0;

    for(i=0; i < sizeof my_name_array; i++){
        printf("%c", my_name_array[i]);
    }

	//TODO:
    // Print out the array character-by-character
    return 0;
}
