#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int G;
	float x;
	float y;
	float Z;
	float I;
	float J;
	float R;
	int F;

} codes;

codes code;

int main()
{
    code.G = 10;
    code.x = 98;
    code.y = 77;
    code.Z = 55;
    code.I = 40;
    code.J = 33;
    code.R = 222;
    code.F = 100;


    printf("G: %d X: %f Y: %f Z: %f I: %f J: %f R: %f F: %d\n", code.G, code.x, code.y, code.Z, code.I, code.J, code.R, code.F);

    code = (codes){0};

    printf("G: %d X: %f Y: %f Z: %f I: %f J: %f R: %f F: %d\n", code.G, code.x, code.y, code.Z, code.I, code.J, code.R, code.F);

    return 0;
}
