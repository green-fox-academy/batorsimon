#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main()
{

    uint8_t number = 254;
	uint8_t result;

	result = number + 23;
	// Check the result with printf
	printf("%d\n", result);

 	// What happened?!
 	//t�l nagy volt az �rt�k 8bithez


	// Try again with different datatype
	uint16_t result_16 = number + 23;
	// Check the result with printf
     printf("%d\n", result_16);
	// What happened and why?
    //most megkaptuk a teljes sz�mot mert volt el�g bitje kisz�molni


	//----------------------------------------
	int8_t number_negative = -number;
	// Check the result with printf
    printf("%d\n", number_negative);
	// What happened and why?
	//el�jel v�lt�s

    return 0;
}
