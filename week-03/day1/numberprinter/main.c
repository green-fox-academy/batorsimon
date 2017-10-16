#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int printf_numbers(uint64_t from, uint64_t to)
{
    int i = 0;
	for (i = from; i < to; i++)
		printf("%d,", i);
}

int main()
{
	printf_numbers(2147483600, 2147484600);
	return 0;
}
