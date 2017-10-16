#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int int_to_bin_digit(int in, int count)
{
    /*
	int mask = 1U << (count);
	int i = 0;
	for (i = 0; i < count; i++) {
		int result = (in & mask) ? 1 : 0;
		printf("%d", result);
		in = in < 1;
	}


	16     0001 0000
    32     0010 0000

    16 & 32
    0000 0000

	*/

	uint8_t a = 0b00010000;
    printf("Binaris kiiratas a: ");
    printf("%c", (a & 1<<7 ? '1' : '0'));
    printf("%c", (a & 1<<6 ? '1' : '0'));
    printf("%c", (a & 1<<5 ? '1' : '0'));
    printf("%c", (a & 1<<4 ? '1' : '0'));
    printf("%c", (a & 1<<3 ? '1' : '0'));
    printf("%c", (a & 1<<2 ? '1' : '0'));
    printf("%c", (a & 1<<1 ? '1' : '0'));
    printf("%c", (a & 1    ? '1' : '0'));
    printf("\n");

    uint8_t b = 0b00100000;
    printf("Binaris kiiratas b: ");
    printf("%c", (a & 1<<7 ? '1' : '0'));
    printf("%c", (a & 1<<6 ? '1' : '0'));
    printf("%c", (a & 1<<5 ? '1' : '0'));
    printf("%c", (a & 1<<4 ? '1' : '0'));
    printf("%c", (a & 1<<3 ? '1' : '0'));
    printf("%c", (a & 1<<2 ? '1' : '0'));
    printf("%c", (a & 1<<1 ? '1' : '0'));
    printf("%c", (a & 1    ? '1' : '0'));
    printf("\n");


    uint8_t c = a & b;
    printf("%d\n",c);
    if(c){
        printf("true\n");
    } else {
        printf("false\n");
    }
}


int main()
{
    int_to_bin_digit(16, 32);
    return 0;
}
