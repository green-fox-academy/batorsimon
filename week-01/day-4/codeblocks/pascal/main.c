#include <stdio.h>
#include <stdlib.h>


/*
create a program which draws a diamond, like this:
123456*123456
1234* * *1234
12* * * * *12
* * * * * * *
* * * * * * *
12* * * * *12
1234* * *1234
123456*123456

(6* 8) +1 oszlop teli + (6*8)

 *
 *  *  *  *  *  *
 *  *  *  *  *  *
 *  *  *  *  *  *
 *  *  *  *  *

 1x5


*/


int main()
{
    int i;
    int j;
    int k;
    int l;


    for (j=0; j< 4; j++){ //sorok

        printf(" * \n");

        for(k=0; k<6; k++){  //oszlopok
             printf(" * ");
        }


       }



    return 0;
}
