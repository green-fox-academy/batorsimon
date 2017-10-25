#include <stdio.h>
#include <stdlib.h>

void string_copy(char *dest, char *source);

int main()
{
    char my_string[] = "to be copied";
    char dest[50];
    //TODO: write a function, which copies a string to the 'dest' array, then print out in string format.
    string_copy(dest, my_string);
    return 0;
}

void string_copy(char *dest, char *source)
{
    int i = 0;
    for(i = 0; source[i] != '\0' ; i++) {
        dest[i] = source[i];
        printf("The %d. element of source array: %c and destination: %c\n", i, source[i], dest[i]);
    }

}
