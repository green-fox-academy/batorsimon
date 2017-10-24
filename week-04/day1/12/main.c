#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int size);

int main()
{
	int a[] = {6, 8, 48, 1, -9, 89};

	//TODO: write a function, which prints out the passed array's elements.

	int a_size = sizeof(a) / sizeof(int);
	print_array(&a, a_size);
	return 0;
}

void print_array(int *array, int size)
{
    int i = 0;
    for(i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}
