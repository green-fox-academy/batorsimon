#include <stdio.h>
#include <stdlib.h>


/*
write a program to find the largest number of three
*/


int main()
{
    int a = 13;
    int b = 29;
    int c = 7;

    if(a>b && a>c){
        printf("Az a: a legnagyobb szam!\n");
    }
     if(b>a && b>c){
        printf("A: b a legnagyobb szam!\n");
    }
     if(c>a && c>b){
        printf("A: c a legnagyobb szam!\n");
    }


    printf("Hello world!\n");

    return 0;
}
