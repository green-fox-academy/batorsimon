#include <stdio.h>
#include <stdlib.h>

int main()
{
    int  i = 2;
	float f = 13.5, result;

	result = f / i;
	//TODO: print out the f/i quotient
    printf("%f", result);
	//QUESTION: do you need explicit conversion?
	//no because the result is in float so capable of storeing the value

    return 0;
}
