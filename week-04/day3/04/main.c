#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct rectangular_cuboid{
    double a;
    double b;
    double c;
};

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface

float getsurface(struct rectangular_cuboid rect)
{
    float surface = (2*(rect.a*rect.b + rect.a*rect.c + rect.b*rect.c));
    return surface;
}

// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume

float getvolume(struct rectangular_cuboid rect)
{
    float volume = rect.a * rect.b * rect.c;
    return volume;
}

int main()
{
    struct rectangular_cuboid rect = {2.3, 4.4, 6.2};

    printf("The surface calculated: %.2f\nThe volume calculated: %.2f\n",getsurface(rect), getvolume(rect) );
    return 0;
}
