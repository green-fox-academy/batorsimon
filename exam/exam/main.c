#include <stdio.h>
#include <stdlib.h>

void task();
void multiple(float temp[]);

int main()
{
    float array[30] = { 23.4, 55.2, 22.6, 3.83, 40.5, 18.66};
    task();
    multiple(array);

    return 0;
}


void multiple(float temp[]) {
    int i = 0;
    float sum = 0;
    float avg = 0;

    printf("The array before multiplying: \n");

    for(i; temp[i] != '\0'; i++) {
        sum += temp[i];
        printf("%.2f\n", temp[i]);
    }

    avg = sum / i;
    printf("\nThe sum of the array: %f\n", sum);
    printf("The average of the array: %f\n\n", avg);
    printf("The array after it is multiplied with the average of it: \n");

     for(i = 0; temp[i] != '\0'; i++) {
        temp[i] = (temp[i] * avg);
        printf("%.2f \n", temp[i]);
    }

}

void task() {
    printf("Welcome!\n");
    printf("Today i am going to write a little example of passing an entire array. \n");
    printf("I am going to create a function that takes an array of floats.\n");
    printf("Then the function multiplies each element with the average of the array.\n\n");
}
