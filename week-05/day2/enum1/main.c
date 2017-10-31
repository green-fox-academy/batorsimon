#include <stdio.h>
#include <stdlib.h>

/*
 * Take exercise array_function_04.c
 *
 * We're creating an exploration oput of it.
 * Create a program that takes user input,  kinds: 'q' 'w' 'a' 's' 'd'.
 * For 'q' it quits.
 * For 'w' ig oeas up if possible.
 * For 'a' it goes left, for 's' down, for 'd' to the right if possible.
 * Create enums fot these steps.
 *
 * Let the user explore the chess board and write out at each case whether the place is empty
 * or if there is a figure, which one is there.
 * And also, if there is a figure which places it could go to, with the possible targets coordinates.
 */

int main()
{
    enum moves {
        q = 'quit',
        w = 2,
        a = 3,
        s = 4,
        d = 5
    };

    while(1) {
        char a;
        scanf("%c", a);
        if(a == q){
            exit(0);
        } else if(a == w){

        } else if(a == a){

        } else if(a == )
    }
    return 0;
}
