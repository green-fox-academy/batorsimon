#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main()
{
	int x, y;
	x = 5;
	y = 8;
	printf("Before Swapping\nx = %d\ny = %d\n", x, y);

	swap(&x, &y);
	printf("After Swapping\nx = %d\ny = %d\n", x, y);

	//TODO: write a function which swaps the values of x and y. Then print out the values of x and y.

	return 0;
}

swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
