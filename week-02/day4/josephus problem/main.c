#include <stdio.h>
#include <stdlib.h>

//The problem — given the number of people, starting point, direction, and number to be skipped —
//is to choose the position in the initial circle to avoid execution.

/* If n=2^m+l and 0<=l<2^m, then  f(n)=2*l+1.
n number of people
k-1 skipped people
k executed

If n is even, then choose l and  m such that n/2 2m+l
If n is odd, then choose l and m :(n-1)/2
*/

int main()
{
    int josephus_position= 1;
    int number_of_people = 13;
    int starting_point = 2;
    int skipped_people = 2;
    int i = 0;

    for(i = starting_point; i < number_of_people; i = skipped_people){
        if(skipped_people%2==0){
        josephus_position = 3;
        }
        printf("The number of people are in the circle: %d \nYou should stand at %d. position.\n", number_of_people,josephus_position);

    }
    return 0;
}
