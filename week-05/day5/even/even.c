#include <stdio.h>

/**
 * Create a function that prints out the fist "N" positive even numbers.
 * It should take the "N" number as a parameter, and print the output to the console.
 *
 * The output should look like this for 5 as parameter:
 *   0, 2, 4, 6, 8
 *
 * Non-positive "N" numbers should be treated as errors, handle it!
 */

int printing(int N)
{
    if(N < 0){
        printf("Please do not give negative number as a parameter!\n");
        return -1;
    }

    printf("The first %d positive even numbers are: ", N);
    int i = 0;
    for(i = 0; i < N; i++){
        if(i % 2 == 0){
            printf("%d ", i);
            N++;
        }
    }
}

int main()
{
    printing(5);
    return 0;
}
