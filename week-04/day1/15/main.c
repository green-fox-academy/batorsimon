#include <stdio.h>
#include <stdlib.h>

void reverse_name(char *name, char *reversed_name);

int main(void)
{
	char name[] = "Gipsz Jakab";
    char reversed[50];

    //write a function which reverse a name's last name and first name. Use a void function.
    //Put your 'return' value in the second parameter.

    reverse_name(name, reversed);

    return 0;
}

void reverse_name(char *name, char *reversed_name)
{
    char temp[50];

     int i = 0;
    for(i = 0; name[i] != 32 ; i++) {
        temp[i] = name[i];
        printf("The %d. element of source array: %c and destination: %c\n", i, name[i], temp[i]);
    }

    //char space = ' ';
    int j = 0;
    for(i = i+1; name[i] != '\0'; i++) {
        reversed_name[j] = name[i];
        printf("The %d. element of source array: %c and destination: %c\n", i, name[i], reversed_name[j]);
        j++;
    }

    int k = 0;
    for(k = 0; name[i] != '\0'; i++) {
        reversed_name[j] = name[i];
        printf("The %d. element of source array: %c and destination: %c\n", i, name[i], reversed_name[j]);
        j++;
    }



    /*
    int i = 0;
    for(i = 0; name[i] != '\0' ; i++) {
        temp[i] = name[i];

        printf("The %d. element of source array: %c and destination: %c\n", i, name[i], temp[i]);
    }

    printf("--------------------\n");

    int j = 0;
    char a = '\0';
    for(j = name[a]; j >= name[0] ; j--) {
        reversed_name[j] = temp[j];

        printf("The %d. element of source array: %c and destination: %c\n", i, name[i], reversed_name[i]);
    }
    */
}
