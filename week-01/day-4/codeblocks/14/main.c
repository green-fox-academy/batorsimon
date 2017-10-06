#include <stdio.h>
#include <stdlib.h>

/*
modify the previous program to print the table reverse order
for example:
Fahrenheit       Celsius
300               148.9
280               137.8
260               126.7
240               115.6
...
print out at least 10 lines
*/

int main()
{

    float i=0;
    float fahrenheit = 0;
    float celsius = 0;

    for(i=300; i>280; i--){
        fahrenheit = i;
        celsius = (fahrenheit -32)/ 1.8;
        printf("Fahrenheit: %f Celsius: %f\n", fahrenheit, celsius);
    }

    return 0;
}
