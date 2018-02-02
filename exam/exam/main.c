#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void task();
void multiple(float temp[]);
void decision();

int main()
{
   // task();

    float array[30] = { 23.4, 55.2, 22.6, 3.83, 40.5, 18.66};
    //multiple(array);

    decision();

    return 0;
}


void multiple(float temp[]) {
    int i = 0;
    float sum = 0;
    float avg = 0;

    printf("The array before multiplying: \n");

    for(i = 0; temp[i] != '\0'; i++) {
        sum += temp[i];
        printf("The %d. element: %.2f.\n", i+1, temp[i]);
    }

    avg = sum / i;
    printf("\nThe sum of the array: %f\n", sum);
    printf("The average of the array: %f\n\n", avg);
    printf("The array after it is multiplied with the average of it: \n");

     for(i = 0; temp[i] != '\0'; i++) {
        temp[i] = (temp[i] * avg);
        sum += temp[i];
        printf("The %d. element: %.2f.\n", i+1,temp[i]);
    }

    avg = sum / i;
    printf("\nThe sum of the multiplied array: %f\n", sum);
    printf("The average of the multiplied array: %f\n\n", avg);

}

void decision() {

    float array[30];
    int i = 0;
    float temp;
    char antwort[50];
    printf("Do you want to write an array by yourself?  Y or N? \n");
    scanf("%s", antwort);

    if (strcmp(antwort, "Y") == 0) {
        printf("Okay! let's type in some numbers: \n");
        printf("If you are finished press a capital F\n");

        do{
            scanf("%f", &temp);
            array[i] = temp;
            i++;
        } while (strcmp(antwort, "F") == 0);

    } else if (strcmp(antwort, "N") == 0) {
        printf("Then have a nice day!\n");
        printf("I hope you enjoyed this example. Bye :)\n");
        exit(0);
    }

}
void task() {

    printf("1111  1   1     1      11   11\n");
    printf("1      1 1     1 1     1 1 1 1\n");
    printf("1111    1   111111111  1  1  1\n");
    printf("1      1 1   1     1   1     1\n");
    printf("1111  1   1 1       1  1     1\n\n");

    printf("Welcome!\n");
    printf("Today i am going to write a little example of passing an entire array. \n");
    printf("I am going to create a function that takes an array of floats.\n");
    printf("Then the function multiplies each element with the average of the array.");

}
