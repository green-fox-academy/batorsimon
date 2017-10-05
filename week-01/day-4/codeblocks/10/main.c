#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*
write a simple program which can help you decide is it hot enough to turn on the AC or not
for example if temperature 20 or less the output is :
it is too cold for the AC
or, the temperature is between 21-24:
it is up to you to turn on the AC
...
*/

    int temperature;
    temperature = 23;


    if(temperature<=20){
        printf("The temperature is too cold for the AC. The current temperature is: %d\n", temperature);
    }
    if(21<temperature && temperature<24){
        printf("It is up to you to turn on the AC. The current temperature is: %d\n", temperature);
    }
    if(temperature>24){
        printf("Maybe you should turn on the AC. The current temperature is: %d\n", temperature);
    }

    return 0;
}
