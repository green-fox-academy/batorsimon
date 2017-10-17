#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i_array[10] = {260, 259, 258, 257, 256, 255, 254, 253, 252, 251};
    unsigned char uc_array[10];

    /*TODO: write a program, which copies the values from the given array to an unsigned char array
    print out the elements of the unsigned char array, with the "%d" format specifier
    what do you see?

    Source string value:      "6356708"
    Destination string value: "6356698"

    The i_array 0. item is: 260
    The uc_array 0. item is :4
    The i_array 1. item is: 259
    The uc_array 1. item is :3
    The i_array 2. item is: 258
    The uc_array 2. item is :2
    The i_array 3. item is: 257
    The uc_array 3. item is :1
    The i_array 4. item is: 256
    The uc_array 4. item is :0
    The i_array 5. item is: 255
    The uc_array 5. item is :255
    The i_array 6. item is: 254
    The uc_array 6. item is :254
    The i_array 7. item is: 253
    The uc_array 7. item is :253
    The i_array 8. item is: 252
    The uc_array 8. item is :252
    The i_array 9. item is: 251
    The uc_array 9. item is :251       */

    strcpy(uc_array, i_array);

    printf("Source string value:      \"%d\"\n", i_array);
    printf("Destination string value: \"%d\"\n\n", uc_array);

    int i = 0;
    for(i = 0; i < 10; i++) {
        uc_array[i] = i_array[i];
        printf("The i_array %d. item is: %d\n",i, i_array[i]);
        printf("The uc_array %d. item is :%d\n\n",i, uc_array[i]);
    }


    return 0;
}
