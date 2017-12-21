#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    //char str[] ="- This, a sample string.";
    char str[] ="2017.12.01.";
    char year[10];
    char mounth[10];
    char day[10];

    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," ,.-");

    while (pch != NULL)
    {
        printf ("%s\n",pch);
        if(pch > )
        pch = strtok (NULL, " ,.-");
    }

    return 0;
}
