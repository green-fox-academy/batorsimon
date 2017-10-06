#include <stdio.h>
#include <stdlib.h>

//writing ABC with loop like this : aAbBcC...zZ

int main()
{
    char a;
    char b;

    for(a = 'a'; a <= 'z'; a++){
            b=a-32;
            printf("%c%c ", a, b);

    }

    /*
    for(a = 'A'; a <= 'Z'; a++){
        for(b = 'a'; b <='z'; b++){
             printf("%c%c ", a, b);
        }
    }  */

    return 0;
}
