#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buf[20];
    printf("[number] (space) [operator] (space) [number]\n");
    gets(buf);
    int i = 0;
    char *p = strtok (buf, " ");
    char *array[3];

    //tokenizing a string and putting the elements into an array
    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, " ");
    }

    //with a for loop, print out each element of the array
    for (i = 0; i < 3; ++i){
        printf("%s\n", array[i]);
    }

        printf("asdsa asd\\
                asdsad\\
                 asd\\");

    return 0;
}
