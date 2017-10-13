#include <stdio.h>
#include <stdlib.h>

//Josephus Problem is when you have a circle of n people standing
//you want to cross out every second person step-by-step until only one remains

int rows();

int rows(int number)
{
    if (number <= 2)
        return 1;
    else
        return rows(number - 1) * number;
}

int main()
{
    int number_of_people = 0;
    int solider = 0;

     printf("%d\n", rows(10));

    return 0;
}
