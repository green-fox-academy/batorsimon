#include <stdio.h>
#include <stdlib.h>

int main()
{
     char buffer[255];   // Buffer variable for user input

    //TODO: Get the user's name with gets

    //TODO: Print it out with puts

    //TODO: Get the user's pet name with getch

    //TODO: Print it out

    printf("write your username: ");
    gets(buffer);
    puts(buffer);

    printf("Write down your pet's name: ");

    int i=0;
    char c = 0;
    for(i=0; i < buffer; i++) {
            c = getch();
        if(c != '\r'){
            buffer[i] = c;
        }
        else{
            break;
            }
        }
    buffer[i]=0;

    printf("\nYour cat's name is: %s", buffer);

    return 0;
}
