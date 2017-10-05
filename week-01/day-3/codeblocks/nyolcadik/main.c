#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h1 = 350;
	int h2 = 200;
	// tell if the double of h2 is bigger than h1
	h2 = h2*2;
	if(h1 < h2){
        printf("h2 is bigger!\n");
	} else{
    printf("Not bigger!\n");
        }
     printf("%d", h2);
    return 0;
}
