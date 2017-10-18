#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string[55] ="This is a string for testing";
	char *p;

	//TODO: write a program, which lists all position where character 'i' is found

    p = string;
    int i = 0;
    int position = 0;

    for(i=0; i < sizeof string; i++){
        if(string[i] == 'i'){
            position = i;
            printf( "The letter 'i' is can be found at the %d. position.\n", position);
        }
    }

    return 0;
}
