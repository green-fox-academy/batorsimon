#include <stdio.h>
#include <stdlib.h>

char_to_ascii();

int main()
{
    //as you know, a character is represented as a numeric value(ASCII value) in the memory
    //write a function which asks for one charcter and prints out the character in character format then in ASCII too
    printf("Type in one character then press enter: ");
    char_to_ascii();
    printf("The character was: %c and the ASCII value of it is: %d",b,c);

    return 0;
}

char_to_ascii() {
    char b;
    gets(b);
    puts(b);
    int a = 0;
    int c = 0;
    for(a = 'A'; a <= 'z'; a++){
           // printf("ASCII value of character %c = %d\n", a, b);
            if(b == a){
                c = a;
            }
            //printf("ASCII value of character %c = %d\n", a, b);
            //b++;
    }
    return c;

}
