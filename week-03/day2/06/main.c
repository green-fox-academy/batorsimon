#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float f_array[10] = {5.6, 8.73, 0.15, 0.99, 1.5, 6.3589, 10.01, -33.0, 0, 15};
    int i_array[10];

	//TODO: write a program, which copies the values from the given array to an integer array
    //print out the elements of the integer array, with the "%d" format specifier
    /*what do you see?
    Source string:      "6356712"
    Destination string: "6356672"
    and the int array cant manage the float values correctly
     */

    strcpy(i_array, f_array);

    printf("Source string value:      \"%d\"\n", f_array);
    printf("Destination string value: \"%d\"\n", i_array);
    printf("Destination string(atoi): \"%d\"\n", atoi(i_array));

    int j = 0;
    float b = 0;
    float c = 0;
    for(j = 0; j < 10; j++) {
           b = f_array[j];
           i_array[j] = f_array[j];
           c = i_array[j];
           printf("f_array %d. item: %.3f\n", j, b);
           printf("i_array %d. item: %.0f\n", j, c);
    }

    return 0;
}
