#include <stdio.h>
#include <stdlib.h>

/*
store your age, height(for example: 1.85 in meters) as different variables
print them out, using only one printf function
use correct variables for each
*/

int main()
{
    int age = 24;
    float height = 1.85;

    do
    {
      printf("A korom: %d es a magassagom: %f meter\n",age, height);
    } while(age==24 && height==1.85);

    return 0;
}
