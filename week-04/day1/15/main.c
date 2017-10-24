#include <stdio.h>
#include <stdlib.h>

//write a function which reverse a name's last name and first name. Use a void function.
//Put your 'return' value in the second parameter.

void reverse_name(char *name, char *reversed_name);

int main(void)
{
	char name[] = "Gipsz Jakab";
    char reversed[50];
    reverse_name(name, reversed);
    return 0;
}

void reverse_name(char *name, char *reversed_name)
{
    char temp[50];
    printf("Original name: %s\n\n", name);
    int i = 0;
    for(i = 0; name[i] != 32 ; i++) {
        temp[i] = name[i];
        //printf("The %d. element of source array: %c and destination: %c\n", i, name[i], temp[i]);
    }

    //printf("%s\n %s\n %s\n", name, temp, reversed_name); //tempben = gipsz (first name) !

    int j = 0;
    for(i = i+1; name[i] != '\0'; i++) {
        reversed_name[j] = name[i];
        //printf("The %d. element of source array: %c and destination: %c\n", i, name[i], reversed_name[j]);
        j++;
    }
    reversed_name[j] = ' ';
    reversed_name[j+1] = '\0';  //puts space and the of the string between the switched names

    //printf("%s\n", reversed_name); // reversed_name = jakab(second name) !
    //printf("%s %s\n\n", reversed_name, temp); //prints the name reversed-cheat

    for(i = 0; reversed_name[i] != '\0'; i++);  //stores the length of reversed name

    for(j = 0; temp[j] != '\0'; j++, i++)
    {
        reversed_name[i] = temp[j];
    }
    reversed_name[i] = '\0';
    printf("The name reversed: %s\n", reversed_name);

}
