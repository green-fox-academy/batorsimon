#include <stdio.h>
#include <stdlib.h>

char_to_ascii();

int main()
{
    //as you know, a character is represented as a numeric value(ASCII value) in the memory
    //write a function which asks for one charcter and prints out the character in character format then in ASCII too
    printf("Type in one character then press enter: ");
    char_to_ascii();
    return 0;
}

char_to_ascii() {
    char c;
    scanf("%c", &c);
    printf("The ASCII value of the character: %c is: %d ", c, c);
}
