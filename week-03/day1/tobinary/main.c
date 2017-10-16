#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*  16     0001 0000
    32     0010 0000

   16 & 32 0000 0000           */

int int_to_bin_digit(int in, int count)
{

	int mask = 1U << (count);
	int i = 0;
    printf("The number %d and %d bitwise ANDed together is: ", in, count);
	for (i = 0; i < count; i++) {
		int result = (in & mask) ? 1 : 0;
		printf("%d", result);
		//in = in < 1;
	}
}

int main()
{
    int_to_bin_digit(16, 32);
    return 0;
}
