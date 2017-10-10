#include <stdio.h>
#include <stdlib.h>

int main()
{
     int arr[50];

    // TODO: write a program witch asks for a number, that will be the real size of the array (50 elements are allocated, that's the maximum size)
    // Then load up the array with integer values
	// print out the array
    // Then ask for a number, that will be the position, where you want the element to be deleted
    // handle the problem when trying to delete from invalid positions (e.g. negative number)
    // print out the the array after the deleting

    int a = 0;
    int b = 0;
    printf("Write a number between 1 and 50, which will be the size of your array: ");
    scanf("%d", &a);

    if(a > 50 | a<=0){
        printf("Number isnt between the argument!");
        exit(0);
    }

    int i = 0;
    for(i = 0; i < a; i++) {
            arr[i] = i;
            //arr[i] = arr[i+1]; ha azt akarom hogy a 0. memória címen az 1-es legyen
            printf("%d\n", arr[i]);
    }

    printf("Write a number, that will be the position, where you want the element to be deleted: ");
    scanf("%d", &b);

    if(b > a | b < 1){
                printf("Not valid position!");
                exit(0);
            }

    int j = 0;
    int k = 0;
    for(k = 0; k < b; k++){
            arr[k]= k ;
            printf("%d \n", arr[k]);
    }

    for(j = b; j < a; j++) {
            if (j == b) {
                a = a - 1;
                }
            arr[j] = arr[j+1];
            printf("%d \n", arr[j]);
    }

    return 0;
}
