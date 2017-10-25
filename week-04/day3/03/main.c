#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} point_t;

// Todo: Create a function the constructs a point
// It should take it's x and y coordinate as parameter
// Create a function that takes 2 Points as a pointer and returns the distance between them

point_t point(int x, int y){
    point_t point;
    point.x = x;
    point.y = y;

    return point;
}

float distance(point_t point1, point_t point2) {
    float a = sqrt(pow((point2.x - point1.x),2) + pow((point2.y - point1.y),2));
    return a;
}
int main()
{
    point_t point1 = {4, 8};
    point_t point2 = {10, 3};

    printf("The distance between point1 and point2 is: %f.", distance(point1, point2));
    return 0;
}
