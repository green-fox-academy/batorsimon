#include <stdio.h>
#include <string.h>

/* Create a function that can reverse a string (char array)
 * It should take the string as a parameter and prints out
 * the reversed string.
 *
 *  Example:
 * input:  reverse_string("Green Fox")
 * output: xoF neerG
 *
 * In case of invalid parameter (integers) the function should
 * print out : "invalid parameter"
 */

void reversing(char *arr, char *reversed)
{
    char first_part[50];
    printf("Original name: %s\n", arr);
    int i = 0;
    for(i = 0; arr[i] != 32 ; i++) {
        first_part[i] = arr[i];
    }
    first_part[i] = ' ';
    first_part[i+1] = '\0';

    int j = 0;
    char second_part[50];
    for(i = i+1; arr[i] != '\0'; i++) {
        second_part[j] = arr[i];
        j++;
    }
    second_part[j] = ' ';
    second_part[j+1] = '\0';

/*
    char temp[50];
    for(i = 0; first_part[i] != '\0'; i++);
    int a = 0;
    for(j = i-1; j >= 0; j--){
        temp[a] = first_part[j];
        a++;
    }
    temp[a] = '\0';

    char temp2[50];
    for(i = 0; second_part[i] != '\0'; i++);
    a = 0;
    for(j = i-1; j >= 0; j--){
        temp2[a] = second_part[j];
        a++;
    }
    temp2[a] = '\0';


    for(i = 0; temp[i] != '\0'; i++)
    {
        reversed[i] = temp[i];
    }
    a = 0;
    for(i; temp2[a] != '\0'; i++)
    {
        reversed[i] = temp2[a];
        a++;
    }
    reversed[i] = '\0';
    string copy helyett
    */


    strrev(first_part);
    strrev(second_part);
    strcpy(reversed, second_part);
    strcat(reversed, first_part);

    printf("The name switched and reversed: %s\n", reversed);
}

int main()
{
    char arr[] = "Green Fox";
    char reversed[50];
    reversing(arr, reversed);

    return 0;
 }
