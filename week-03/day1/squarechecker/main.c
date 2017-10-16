#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This program should work correctly with the following input: 20, 400

int main()
{
    float number = 0;
    float result = 0;
	printf("Please enter a number: ");
	fflush(stdin);
	scanf("%f", &number);
	number = pow(number, 2);

	printf("Please enter the square of that number: ");
	fflush(stdin);
	scanf("%f", &result);

	if (number == result)
		printf(":)\n");
	else
		printf(":(\n");
		printf("%f\n", result);

    return 0;
}
