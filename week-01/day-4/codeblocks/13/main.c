#include <stdio.h>
#include <stdlib.h>

/*
create a program which converts the fahrenheit to celsius
the output should look like this:
Fahrenheit       Celsius
  0               -17.8
 20                -6.7
 40                 4.4
 60                15.6
...
print out at least 10 lines
*/


int main()
{
    float i;
    float fahrenheit = 0;
    float celsius = 0;

    for(i=1; i<11; i++){
        celsius = i;
        fahrenheit = (1.8 * celsius)+32;
        printf("Fahrenheit: %f Celsius: %f\n", fahrenheit, celsius);
    }

    /*
    float celsius, fahrenheit;

     printf("\nEnter temp in Celsius : ");
     scanf("%f", &celsius);

     fahrenheit = (1.8 * celsius) + 32;
     printf("\nTemperature in Fahrenheit : %f ", fahrenheit);
     */

    return 0;
}
