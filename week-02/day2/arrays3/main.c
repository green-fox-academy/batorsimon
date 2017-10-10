#include <stdio.h>
#include <stdlib.h>

int main()
{
    int int_array[] = {1, 654, 987, 654, 31};
    float float_array[] = {1.2, 3.14, 1.41, 0.707, 1.73};

    printf("The int array: \n");

    int i = 0;
    int length_array = sizeof int_array / sizeof int_array[0];
    for(i = 0; i < sizeof length_array; i++) {
        printf("%d\n", int_array[i]);
    }

    printf("\nThe float array: \n");

    int j = 0;
    int length_array2 = sizeof float_array / sizeof float_array[0];
    for(j = 0; j < sizeof length_array2; j++) {
        printf("%.3f\n", float_array[j]);
    }

	//TODO:
    // Print out the content of the arrays
    return 0;
}
