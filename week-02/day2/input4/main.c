#include <stdio.h>
#include <stdlib.h>

void func();

int main()
{
    //write a void function which asks for a number with scanf and print it out with printf, then asks for a name with gets, and print it out with puts
    //you will notice something is wrong
    //try to solve the problem

    //because gets also stores the final newline (\n) character in your buffer -- if your code is not expecting this, you should remove it manually
    //for example i removed with fflush(stdin); it clears the console

    func();
    return 0;
}

void func()
{
     int a;
     printf("Please write a number: ");
     scanf("%d", &a);
     printf("Your number was: %d\n", a);
     fflush(stdin);

     char b[4];
     printf("Please write your name: ");
     gets(b);
     printf("Your name was: ");
     puts(b);
}
