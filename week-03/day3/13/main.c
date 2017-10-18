#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[] = "This is a sample string";
  //  char *first, *last;

	//TODO: write a program which prints out the distance between the first and last occurance of character 's'


	printf("%s\n", str);

    int first = 0;
    int last = 0;
    int i = 0;
    int distance = 0;

    for(i = 0; i < sizeof str; i++){
        if(str[i] == 's'){
            first = i;
            printf( "The letter 's' is can be found first time at the %d. position.\n", first);
             break;
        }

    }
    for(i = sizeof str; i > 0; i--){
        if(str[i] == 's'){
            last = i;
            printf( "The letter 's' is can be found last time at the %d. position.\n", last);
             break;
        }

    }
    distance = last - first;
    printf("The distance between the first and the last 's' character is %d.\n", distance);

    return 0;
}
