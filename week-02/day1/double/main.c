#include <stdio.h>
#include <stdlib.h>

// create a function called `doubling` that doubles it's input parameter
// again the parameters value should be stored in a .h file

#include "parameters.h"
int doubling();

int main()
{
    doubling();
    return 0;
}

int doubling()
{
    printf("The given number is: %d, the double of this number is: %d.\n", a, a*2);
    printf("The given number is: %d, the double of this number is: %d.\n", b, b*2);
    printf("The given number is: %d, the double of this number is: %d.\n", c, c*2);
    printf("The given number is: %d, the double of this number is: %d.\n", d, d*2);
    printf("The given number is: %d, the double of this number is: %d.\n", e, e*2);
}
