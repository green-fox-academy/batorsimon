#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14

void circle(char c, int x);
void radians();

int main()
{
    //circle('*', 14);

    int i,j,rows = 5;
     for(i = 1; i <= rows; i++) {  //create the number of rows

        for(j = 1; j <= i ; j++) {  //how many rows(the first row one and than ++

                printf("%d", i);

        }
        printf("\n");
    }

   for(i = rows; i >= 1; i--) {  //create the number of rows

        for(j = 1; j <= i ; j++) {  //how many rows(the first row one and than ++

                printf("%d", i);

        }
        printf("\n");
    }

    return 0;
}

void circle(char c, int x) {

    int i = 0;
    int j = 0;

    for(i = -x; i < x; i++)
    {
        for(j = -x; j < x; j++)
        {
            if(i*i + j*j < x*x) {
                printf("%c",c);

            } else {
                printf(" ");

            }
        }
        printf("\n");
    }
}


void radians() {
    int radians = 10;
    int x = 0;
    int y = 0;

    int radius = 4;
    for(radians=0; radians < 2*pi; radians +=.1)
    {
         x = radius*cos(radians);
         y = radius*sin(radians);
          /* display code */
          printf("%d", x);
    }

}
