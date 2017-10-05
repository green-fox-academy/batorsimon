#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main()
{

    int a = 654;
	uint64_t b = 654987312;
	int c = 0;
	// Tell if the reminder of b devided by a is 3
	c = b%a;
	if(c = 3){
        printf("igen\n");
        printf("%d",c);
	}
    return 0;
}
