#include <stdio.h>
#include <stdlib.h>

//Josephus Problem is when you have a circle of n people standing
//you want to cross out every second person step-by-step until only one remains

int circle();

int circle(int soldiers_number, int starting_pos)
{
    if (soldiers_number == 1) {
        return soldiers_number;
    }
    else {
        return (circle(soldiers_number - 1, starting_pos) + starting_pos-1) % soldiers_number + 1;
    }
}

int main()
{
     int soldiers_number, starting_pos;
    printf("Enter the number of soldiers: ");
    scanf("%d", &soldiers_number);
    if (soldiers_number < 1) {
            printf("This is not a positive number");
            exit(0);
    }
    starting_pos = 2;

    printf("The chosen place is %d to survive", circle(soldiers_number, starting_pos));

    return 0;
}
