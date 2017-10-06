#include <stdio.h>
#include <stdlib.h>

int main()
{

    int rows = 7;
    int i = 0;
    int j = 0;
    int k = 0;


    /*create a simple program which generates a triangle like this:
1
22
333
4444
55555
666666
7777777
if you change the rows variable the output should be different as well
*/

    for(i = 1; i <= rows; i++) {  //create the number of rows

        for(j = 1; j <= i ; j++) {  //how many rows(the first row one and than ++

                printf("%d", i);

        }
        printf("\n");
    }


/*
7777777
666666
55555
4444
333
22
1
*/

    for(i = rows; i >= 1; i--) {  //create the number of rows

        for(j = 1; j <= i ; j++) {  //how many rows(the first row one and than ++

                printf("%d", i);

        }
        printf("\n");
    }

    /*
          1
         22
        333
       4444
      55555
     666666
    7777777
    */

    for(i = 1; i <= rows; i++) {  //create the number of rows
             printf("\n");

        for(j = 1; j <= i ; j++) {  //how many rows(the first row one and than ++

                printf("%d", i);

        }


    }

    return 0;
}
